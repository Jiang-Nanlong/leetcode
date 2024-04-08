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
};

int main() {
	Solution st;
	vector<int> heights = { 2, 1, 5, 6, 2, 3 };
	cout << st.largestRectangleArea(heights) << endl;
	cout << st.largestRectangleArea1(heights) << endl;
	return 0;
}
