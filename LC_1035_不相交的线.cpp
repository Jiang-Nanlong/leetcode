#include <iostream>
#include <vector>
using namespace std;

//给定两个数组，找出数组中相同的数组连接起来，但是这些链接的线不能相交。这不就是LeetCode 1143 最长公共子序列的题吗，序列不一定要连续，返回最长的公共子序列的长度

class Solution {
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = 1; j <= nums2.size(); j++) {
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[nums1.size()][nums2.size()];
	}

	//第二次做，这个题就是最长公共子序列的翻版，一模一样
	int maxUncrossedLines1(vector<int>& nums1, vector<int>& nums2) {
		vector<int> dp(nums2.size() + 1, 0);

		for (int i = 1; i <= nums1.size(); i++) {
			int prev = 0;
			for (int j = 1; j <= nums2.size(); j++) {
				int temp = dp[j];
				if (nums1[i - 1] == nums2[j - 1])
					dp[j] = prev + 1;
				else
					dp[j] = max(dp[j], dp[j - 1]);
				prev = temp;
			}
		}
		return dp[nums2.size()];
	}
};

int main() {
	Solution st;
	vector<int> nums1 = { 1, 4, 2 }, nums2 = { 1, 2, 4 };
	cout << st.maxUncrossedLines(nums1, nums2) << endl;
	return 0;

}