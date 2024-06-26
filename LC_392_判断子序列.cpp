#include <iostream>
#include <vector>
using namespace std;

//判断字符串s是否为t的子序列，这里的子序列不一定是连续子序列，也可能是主串删除某些元素以后的序列。
//所以这就和LeetCode 1143 最长公共子序列中一样了，不过也有不同，在递推公式上。

class Solution {
public:
	bool isSubsequence(string s, string t) {
		vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));  //dp[i][j]还是表示以s中以i-1为结尾，t中以j-1为结尾的字符串的公共子序列的长度。
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= t.size(); j++) {
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = dp[i][j - 1];   //因为判断s是不是t的子序列，s是dp数组的行，t是dp数组的列，s的长度应该是小于等于t的，所以这里如果s[i-1]!=t[j-1]的话，只需要让
				//dp[i][j]等于上一个t的长度就行，即dp[i][j]=dp[i][j-1]
			}
		}
		if (dp[s.size()][t.size()] == s.size()) return true;
		return false;
	}

	//第二次做，开始的时候按着最长公共子序列的写法做也通过了
	// 后来看了一下答案，感觉答案说的也挺多。
	// 这个题主要是为了在长字符串中匹配短的，所以如果当前字符不匹配，只需要让长的回退一个就行，也就是等于长串中上一个字符的最长序列长度就行。
	bool isSubsequence1(string s, string t) {
		vector<int> dp(t.size() + 1, 0);
		for (int i = 1; i <= s.size(); i++) {
			int prev = 0;
			for (int j = 1; j <= t.size(); j++) {
				int temp = dp[j];
				if (s[i - 1] == t[j - 1])
					dp[j] = prev + 1;
				else
					dp[j] = dp[j - 1];
				prev = temp;
			}
		}
		return dp[t.size()] >= s.size();
	}
};

int main() {
	Solution st;
	string s = "abc", t = "ahbgdc";
	cout << boolalpha << st.isSubsequence(s, t) << endl;
	cout << st.isSubsequence1(s, t) << noboolalpha << endl;
	return 0;
}