#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//求柱状图中最大的矩形面积，这个题和接雨水的题正好相反，接雨水的题是求height[i]两边最高的柱子，而这个要求最小的。所以先找出左右两边第一个最小的柱子，这两个最小柱子中间围起来的就是以height[i]为高的矩形


class Solution {
public:

	int largestRectangleArea(vector<int>& heights) {
		vector<int> minLeftIndex(heights.size());
		vector<int> minRightIndex(heights.size());
		int size = heights.size();

		minLeftIndex[0] = -1;
		for (int i = 1; i < size; i++) {
			int t = i - 1;
			//while (t >= 0 && heights[t] >= heights[i]) t--;  //这么写的话会超时，因为t是一步一步移动的
			while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];   //这样的话t就能依靠之前的结果进行移动
			minLeftIndex[i] = t;
		}

		minRightIndex[size - 1] = size;
		//for (int i = 0; i < size - 1; i++) {  //同样这么写也会超时
		//	int t = i + 1;
		//	while (t < size && heights[t] >= heights[i]) t++;
		//	//while (t < size && heights[t] >= heights[i]) t = minRightIndex[t]; //这里改成这样的话，就会陷入死循环，因为我们最开始初始化minRightIndex是初始化的最后一个，所以这里的for循环应该倒序遍历
		//	minRightIndex[i] = t;
		//}

		for (int i = size - 2; i >= 0; i--) {
			int t = i + 1;
			while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
			minRightIndex[i] = t;
		}

		int res = 0;
		for (int i = 0; i < size; i++) {
			int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
			res = max(sum, res);
		}
		return res;
	}

	//单调栈做法，求的是第一个比heights[i]小的元素
	int largestRectangleArea1(vector<int>& heights) {
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		//这两行比较重要，在接雨水的那个题中没有这两行是因为那个题里不用考虑两端的柱子，这里不一样，这里要考虑两端的
		//如果没有最后的0，那么对于{2,4,6,8}这样的数组时，就计算不出结果，因为每一步的height[i]都是大于heights[stk.top()]的，
		//同理，如果没有第一个0，那么对于{8,6,4,2}这样的数组时，最后栈内就会只剩一个8，这时候就计算不出第一个矩形的结果了
		stack<int> stk;
		int sum = 0;
		for (int i = 0; i < heights.size(); i++) {
			while (!stk.empty() && heights[i] < heights[stk.top()]) {
				int h = heights[stk.top()];
				stk.pop();
				if (!stk.empty()) {  //因为数组两头加了两个0，所以这个判断语句可以省略，因为当遍历到最后一个0的时候，栈内也只会有一个0，又因为while循环的判断条件是heights[i] < heights[stk.top()]
					//所以这时候根本不会进入循环，正好数组也遍历完了，就直接退出了。
					int w = i - stk.top() - 1;
					sum = max(sum, h * w);
				}
			}
			stk.push(i);
		}
		return sum;
	}

	//这个题用单调栈的做法，看出是要求第一个小于栈顶元素的值了，但是没有处理好边界问题
	//还是看了答案以后，答案上是在开头和结尾插入0来使解法更一般化
	int largestRectangleArea2(vector<int>& heights) {
		stack<int> stk;
		heights.insert(heights.begin(), 0);
		heights.insert(heights.end(), 0);
		int res = 0;
		for (int i = 0; i < heights.size(); i++) {
			while (!stk.empty() && heights[i] < heights[stk.top()]) {
				int high = heights[stk.top()];
				int right = i;
				stk.pop();
				int left = stk.top();
				res = max(res, (right - left - 1) * high);
			}
			stk.push(i);
		}
		return res;
	}

	//但是感觉在第一个位置插入0太耗时了。分析一下可以知道，第一个位置插入0是为了防止某个柱子高度最低，是的最后矩形的长为整个数组的长度。
	//但是真要出现这种情况的话，也就是说在原数组中，在它之前不可能有比它更小的值了。对应到栈中，它就是栈底，所以此时只需要把矩形的长设为数组的长就行。
	// 
	//虽说这样可以去掉第一个插入的0，但是最后一个插入的不太好去掉，因为这会导致整个循环长度发生变化，最后就要另起循环来清空栈内元素。
	//这样的话，相比于在数组最后插入0来说，会更麻烦。
	int largestRectangleArea3(vector<int>& heights) {
		stack<int> stk;
		heights.insert(heights.end(), 0);
		int res = 0;
		for (int i = 0; i < heights.size(); i++) {
			while (!stk.empty() && heights[i] < heights[stk.top()]) {
				int high = heights[stk.top()];
				int right = i;
				stk.pop();
				int left = -1;
				if (!stk.empty())
					left = stk.top();
				res = max(res, (right - left - 1) * high);
			}
			stk.push(i);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> heights = { 2, 1, 5, 6, 2, 3 };
	cout << st.largestRectangleArea(heights) << endl;
	cout << st.largestRectangleArea1(heights) << endl;
	cout << st.largestRectangleArea2(heights) << endl;
	cout << st.largestRectangleArea3(heights) << endl;
	return 0;
}