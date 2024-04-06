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
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,3,1 };
	cout << st.rob(nums) << endl;
	return 0;
}
