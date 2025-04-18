#include <iostream>
#include <vector>
using namespace std;

//还是跟打家劫舍那题一样，不过这里的房子会连成环
//所以就分三种情况，第一种就是头尾元素都不取；第二种就是不取尾元素；第三种就是不取首元素
//跟我想到也差不多吧，首元素和尾元素不能同时考虑，每种情况循环一遍，一共两遍

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int result1 = robRange(nums, 0, nums.size() - 2);
		int result2 = robRange(nums, 1, nums.size() - 1);
		return max(result1, result2);
	}
	int robRange(vector<int>& nums, int start, int end) {
		if (start == end) return nums[start];
		vector<int> dp(nums.size());
		dp[start] = nums[start];
		dp[start + 1] = max(nums[start], nums[start + 1]);
		for (int i = start + 2; i <= end; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[end];
	}

	//第二次做，就是分两种情况，取第一个就不能取最后一个，取最后一个就不能取第一个
	int rob1(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int value1 = robHelper(nums, 0, nums.size() - 1);
		int value2 = robHelper(nums, 1, nums.size());
		return max(value1, value2);
	}

	int robHelper(vector<int>& nums, int begin, int end) { // 左闭右开
		if (end - begin == 1)
			return nums[begin];
		vector<int> dp(nums.size(), 0);
		dp[begin] = nums[begin];
		dp[begin + 1] = max(nums[begin], nums[begin + 1]);
		for (int i = begin + 2; i < end; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[end - 1];
	}

// 偷第一个房间就不能偷最后一个，反之亦然。所以分开写，一个是从0~n-1，一个是从1~n
	int rob3(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		int n = nums.size();
		vector<int> dp1(n - 1, 0);
		vector<int> dp2(n, 0);

		dp1[0] = nums[0];
		dp1[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n - 1; i++) {
			dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
		}

		dp2[1] = nums[1];
		dp2[2] = max(nums[1], nums[2]);
		for (int i = 3; i < n; i++) {
			dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
		}
		return max(dp1.back(), dp2.back());
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,3,2 };
	cout << st.rob1(nums) << endl;
	return 0;
}