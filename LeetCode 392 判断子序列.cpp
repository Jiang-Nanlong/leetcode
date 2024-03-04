#include <iostream>
#include <vector>
using namespace std;

//�ж��ַ���s�Ƿ�Ϊt�������У�����������в�һ�������������У�Ҳ����������ɾ��ĳЩԪ���Ժ�����С�
//������ͺ�LeetCode 1143 �������������һ���ˣ�����Ҳ�в�ͬ���ڵ��ƹ�ʽ�ϡ�

class Solution {
public:
	bool isSubsequence(string s, string t) {
		vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));  //dp[i][j]���Ǳ�ʾ��s����i-1Ϊ��β��t����j-1Ϊ��β���ַ����Ĺ��������еĳ��ȡ�
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= t.size(); j++) {
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = dp[i][j - 1];   //��Ϊ�ж�s�ǲ���t�������У�s��dp������У�t��dp������У�s�ĳ���Ӧ����С�ڵ���t�ģ������������s[i-1]!=t[j-1]�Ļ���ֻ��Ҫ��
				//dp[i][j]������һ��t�ĳ��Ⱦ��У���dp[i][j]=dp[i][j-1]
			}
		}
		if (dp[s.size()][t.size()] == s.size()) return true;
		return false;
	}
};

int main() {
	Solution st;
	string s = "abc", t = "ahbgdc";
	cout << boolalpha << st.isSubsequence(s, t) << endl;
	return 0;
}