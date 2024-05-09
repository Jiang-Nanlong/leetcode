#include <iostream>
#include <vector>
using namespace std;

//给定一个字符串，返回其中最长的回文子序列的长度，这个题和LeetCode 647 回文子串还不一样，这个题的子序列可以是不连续的，就比如测试用例s="bbbab"，结果是4，一个可能的最长回文子序列是"bbbb"
//再就是dp[i][j]表示的是s[i]和s[j]范围内的最长回文子序列的长度。我看了递推公式以后还是想不通怎么表示的回文子序列可以是不连续的。
//子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
//打印完dp数组，跟着推了一遍发现还是看不懂为什么递推公式这么写

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i + 1; j < s.size(); j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++)
				cout << dp[i][j] << "   ";
			cout << endl;
		}

		return dp[0][s.size() - 1];
	}

	// 第二次做，还是没有做出来
	// dp[i][j]表示的是s[i]和s[j]范围内(左闭右闭区间)的最长回文子序列的长度
	int longestPalindromeSubseq1(string s) {
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		for (int i = 0; i < s.size(); i++)
			dp[i][i] = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i + 1; j < s.size(); j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][s.size() - 1];
	}
};

int main() {
	Solution st;
	string s("bbbab");
	cout << st.longestPalindromeSubseq(s) << endl;
	cout << st.longestPalindromeSubseq1(s) << endl;
	return 0;
}