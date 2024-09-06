#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组和一个整数k，如果一个子序列中最多有k对元素互不相同，则称这是一个好子序列。返回一个最长的好子序列的长度。

// 这个题的动态规划解法还没看懂，现在只有记忆化搜索。

class Solution {
public:
	int maximumLength(vector<int>& nums, int k) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(k + 1, 1));  // dp[i][j]表示以nums{i]为结尾的子序列且有j对元素互不相同的最长子序列的长度
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				int flag = nums[i] == nums[j] ? 0 : 1;  // 判断nums[i]与nums[j]是否相同
				for (int h = 0; h + flag <= k; h++) {   // 从头遍历允许的互不相同的元素对数
					if (dp[i][h + flag] < dp[j][h] + 1)
						// 如果以nums[i]为结尾且有h+flag对互不相同元素的子序列的最大长度 小于 以nums[j]为结尾且有h对互不相同的元素的子序列的最大长度+1
						// 则修改这里的以nums[i]为结尾且有h+flag对互不相同元素的子序列的最大长度
						dp[i][h + flag] = dp[j][h] + 1;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++)
				res = max(res, dp[i][j]);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,1,1,3 };
	int k = 2;
	cout << st.maximumLength(nums, k) << endl;
	return 0;
}