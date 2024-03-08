#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		vector<int> res(height.size(), -1);
		stack<int> stk;
		for (int i = 0; i < height.size(); i++) {
			while (!stk.empty() && height[i] >= height[stk.top()]) {
				res[stk.top()] = height[i];
				stk.pop();
			}
			stk.push(i);
		}
		int j = 0, count = 0;

		for (int i = 1; i < res.size(); i++) {
			if (height[i] < height[j] && res[j] != -1) {
				count = count + height[j] - height[i];
			}
			else {
				j = i;
			}
		}
		return count;
	}
	//以上是我自己写的代码，本想先求出每一个位置右边的第一个大的元素，然后再用从左往右遍历，有点之前的区间射气球那题的感觉了，但是这样做的话，对于[4,2,3]这种就求不了

	//下边是代码随想录的程序，他这是横向求的，也就是算出底和高，然后求面积
	int trap1(vector<int>& height) {
		stack<int> stk;
		int count = 0;
		for (int i = 0; i < height.size(); i++) {
			while (!stk.empty() && height[i] > height[stk.top()]) {
				int mid = height[stk.top()];
				stk.pop();
				if (!stk.empty()) {
					int h = min(height[i], height[stk.top()]) - mid;
					int w = i - stk.top() - 1;
					count = count + h * w;
				}
			}
			stk.push(i);
		}
		return count;
	}

	//这题还有暴力解法，纵向来看，每个柱子的存水量取决于它左边的最高柱子和右边的最高柱子中的较矮的那一个与当前柱子之间的差，所以可以对于每个柱子height[i]找出左右最高的柱子
	int trap2(vector<int>& height) {
		int sum = 0;
		for (int i = 0; i < height.size(); i++) {
			if (i == 0 || i == height.size() - 1) continue;  //第0个位置和最后一个位置永远不接雨水

			int rHeight = height[i], lHeight = height[i];
			for (int l = i - 1; l >= 0; l--) {
				if (height[l] > lHeight)
					lHeight = height[l];
			}

			for (int r = i + 1; r < height.size(); r++) {
				if (height[r] > rHeight)
					rHeight = height[r];
			}
			int h = min(rHeight, lHeight) - height[i];
			if (h > 0)sum += h;
		}
		return sum;
	}

	//暴力解法优化后的代码，暴力解法中求左边最大元素和右边最大元素时有很多重复计算，倒不如一次性把所有位置对应的左边最大元素和右边最大元素都计算出来
	//左边的最大元素就是max(height[i-1], maxLeft[i-1])，同理右边的最大元素就是max(height[i+1],maxRight[i+1])
	int trap3(vector<int>& height) {
		if (height.size() <= 2) return 0;
		vector<int> maxLeft(height.size(), 0);
		vector<int> maxRight(height.size(), 0);
		int size = maxRight.size();

		// 记录每个柱⼦左边柱⼦最⼤⾼度
		maxLeft[0] = height[0];
		for (int i = 1; i < size; i++) {
			maxLeft[i] = max(height[i - 1], maxLeft[i - 1]);
		}

		// 记录每个柱⼦右边柱⼦最⼤⾼度
		maxRight[size - 1] = height[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			maxRight[i] = max(height[i + 1], maxRight[i + 1]);
		}

		// 求和
		int sum = 0;
		for (int i = 0; i < size; i++) {
			int count = min(maxLeft[i], maxRight[i]) - height[i];
			if (count > 0) sum += count;
		}
		return sum;

	}
};

int main() {
	Solution st;
	vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << st.trap(height) << endl;
	cout << st.trap1(height) << endl;
	cout << st.trap2(height) << endl;
	cout << st.trap3(height) << endl;
	return 0;
}