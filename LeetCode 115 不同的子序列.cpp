#include <iostream>
#include <vector>
using namespace std;

//给定两个字符串s和t，统计s中有几种组成t的方式
//dp[i][j]的意思是以i-1为结尾的s中有几种以j-1为结尾的t的组成方式
//看完代码随想录dp数组的定义后，我尝试着自己写一下，结果s[i-1]==t[j-1]的递推公式写错了，而且初始化的时候也初始化错了，全都写成0了。
//这个递推公式来自于两部分，一部分是考虑s[i-1]，一部分是不考虑s[i-1]。考虑s[i-1]的话，既然当前字符已经相同了，那么有多少种组成方式就看它的前一个字符，也就是dp[i-1][j-1]
//不考虑s[i-1]的话，可以参考s:bagg和t:bag，s[3]和t[2]是相同的，但是字符串s也可以不⽤s[3]来匹配，即⽤s[0]s[1]s[2]组成的bag


class Solution {
public:
	int numDistinct(string s, string t) {
		vector<vector<unsigned long long>> dp(s.size() + 1, vector<unsigned long long>(t.size() + 1, 0));
		for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;  //第一列初始化这里可以理解为s中有几种组成空字符串的方式
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= t.size(); j++) {
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				//dp[i][j] = dp[i - 1][j] + 1;
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		for (int i = 0; i <= s.size(); i++) {
			for (int j = 0; j <= t.size(); j++)
				cout << dp[i][j] << "  ";
			cout << endl;
		}

		return dp[s.size()][t.size()];
	}
};

int main() {
	Solution st;
	string s = "rabbbit", t = "rabbit";
	cout << st.numDistinct(s, t) << endl;
	return 0;
}