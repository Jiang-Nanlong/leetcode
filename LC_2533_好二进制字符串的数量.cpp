#include <iostream>
#include <vector>
using namespace std;

//给你四个整数 minLength、maxLength、oneGroup 和 zeroGroup 。
//
//好二进制字符串满足下述条件：
//
//字符串的长度在[minLength, maxLength] 之间。
//每块连续 1 的个数是 oneGroup 的整数倍
//例如在二进制字符串 00110111100 中，每块连续 1 的个数分别是[2, 4] 。
//每块连续 0 的个数是 zeroGroup 的整数倍
//例如在二进制字符串 00110111100 中，每块连续 0 的个数分别是[2, 1, 2] 。
//请返回 好 二进制字符串的个数。答案可能很大，请返回对 109 + 7 取余 后的结果。
//
//注意：0 可以被认为是所有数字的倍数。

// 这个题和LeetCode 2466 统计构造好字符串的方案数 一模一样

class Solution {
public:
	int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
		vector<int> dp(maxLength + 1);
		dp[0] = 1;
		int mod = 1e9 + 7;
		for (int i = 1; i <= maxLength; ++i) {
			if (i >= oneGroup) {
				dp[i] = (dp[i] + dp[i - oneGroup]) % mod;
			}
			if (i >= zeroGroup) {
				dp[i] = (dp[i] + dp[i - zeroGroup]) % mod;
			}
		}
		int res = 0;
		for (int i = minLength; i <= maxLength; i++) {
			res = (res + dp[i]) % mod;
		}
		return res;
	}
};

int main() {
	Solution st;
	int minLength = 2, maxLength = 3, oneGroup = 1, zeroGroup = 2;
	cout << st.goodBinaryStrings(minLength, maxLength, oneGroup, zeroGroup) << endl;
	return 0;
}