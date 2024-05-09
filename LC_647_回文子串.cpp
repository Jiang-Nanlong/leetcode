#include <iostream>
#include <vector>
using namespace std;

//给定一个字符串，返回其中回文子串的个数
//开始做这个题不知道怎么设置dp数组，开始设置成一维的了，因为想到这里只有一个字符串，后来发现还是做不了，就看了视频
//这里的dp数组设置的特别巧妙，dp[i][j]表示字符串中从s[i]到s[j]的子串是否是一个回文子串
//那么当s[i]==s[j]时，就分为三种情况：
//0.i==j，i和j指向同一个字符，那么肯定是回文子串了
//1.i=j-1，也就是i和j指向相邻的两个字符，而且这两个字符又是相等的，所以也是一个回文子串
//2.j-i>1，j和i之间隔着多余一个的字符，又因为i和j指向相等的字符，所以只需要看i和j之间的字符串是否为回文子串

class Solution {
public:
	int countSubstrings(string s) {
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		int count = 0;
		for (int i = 0; i < s.size(); i++) {  //初始化，其实这里的初始化和第0种情况一样，每个字符都是一个回文子串，所以既然下边写了三种情况了，这里的初始化写不写都一样
			dp[i][i] = true;
		}
		for (int i = s.size() - 1; i >= 0; i--) {  //这里的遍历顺序也有说法，因为从第三种情况的递推公式可以看出，dp数组是从左下推出右上，所以不能用原来的从上往下，从左往右遍历，而应该是从下往上，从左往右遍历
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j]) {
					if (j - i <= 1)  //前两种情况
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][j - 1];  //第2种情况
				}
				if (dp[i][j]) count++;
			}
		}
		return count;
	}

	//第二次做，还是没有做出来，这个题的递推公式挺简单，就是dp数组的定义难想，如果想不对定义，那么就难找递推公式
	// dp[i][j]表示从s[i]到s[j]的子串是否是一个回文子串
	int countSubstrings1(string s) {
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		int res = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j]) {
					if (j - i <= 1) {
						res++;
						dp[i][j] = true;
					}
					else if (dp[i + 1][j - 1] == true) {
						res++;
						dp[i][j] = true;
					}
				}
			}
		}
		return res;
	}

	//双指针解法，感觉这个更通俗易懂
	int countSubstrings2(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			res += lengthofpalindromic(s, i, i);  // 计算以i为中心的字符串是回文子串的个数
			res += lengthofpalindromic(s, i, i + 1);  // 计算以i和i+1为中心的字符串是回文子串的个数
		}
		return res;
	}

	int lengthofpalindromic(string& s, int left, int right) {
		int res = 0;
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			left--;
			right++;
			res++;
		}
		return res;
	}
};

int main() {
	Solution st;
	string s("aaaaa");
	cout << st.countSubstrings(s) << endl;
	cout << st.countSubstrings1(s) << endl;
	cout << st.countSubstrings2(s) << endl;
	return 0;
}