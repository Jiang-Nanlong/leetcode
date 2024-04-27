#include <iostream>
#include <vector>
using namespace std;

//����һ���ַ���������������Ļ��������еĳ��ȣ�������LeetCode 647 �����Ӵ�����һ���������������п����ǲ������ģ��ͱ����������s="bbbab"�������4��һ�����ܵ��������������"bbbb"
//�پ���dp[i][j]��ʾ����s[i]��s[j]��Χ�ڵ�����������еĳ��ȡ��ҿ��˵��ƹ�ʽ�Ժ����벻ͨ��ô��ʾ�Ļ��������п����ǲ������ġ�
//�����ж���Ϊ�����ı�ʣ���ַ�˳�������£�ɾ��ĳЩ�ַ����߲�ɾ���κ��ַ��γɵ�һ�����С�
//��ӡ��dp���飬��������һ�鷢�ֻ��ǿ�����Ϊʲô���ƹ�ʽ��ôд

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

	// �ڶ�����������û��������
	// dp[i][j]��ʾ����s[i]��s[j]��Χ��(����ұ�����)������������еĳ���
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