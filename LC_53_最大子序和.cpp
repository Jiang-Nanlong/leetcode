/*
给定一个整数数组nums，找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回和的最大值
*/
#include <iostream>
#include <vector>
using namespace std;

//之前用动态规划做过，现在学了动态规划再来看还算简单，现在再用贪心做一下，贪心做的话，如果当前的序列和为负数了，那么就终止，从下一个数开始重新计算
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int m = nums.size();
		int result = INT_MIN, count = 0;
		for (int i = 0; i < m; i++) {
			count += nums[i];
			if (count > result)
				result = count;
			if (count < 0) count = 0;
		}
		return result;
	}
};

int main() {
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	Solution s;
	cout << s.maxSubArray(nums) << endl;
	return 0;
}
