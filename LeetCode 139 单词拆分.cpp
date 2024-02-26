#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//给定一个字符串s，和一个字典wordDict，判断字符串s能否用wordDict中的元素拼接成，wordDict中的单词可以重复使用，不要求全部都使用，能的拼接成的话返回true，否则返回false。
//这个题是要求排列

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {  //遍历背包，对于一个给定容量的背包，从头遍历这些物品，如果背包可以被单词装满，就为true
			for (int j = 0; j < i; j++) {  //遍历物品
				string word = s.substr(j, i - j);
				if (wordSet.find(word) != wordSet.end() && dp[j] == true) {  //感觉这个递推公式有点难想
					dp[i] = true;
				}
			}
		}
		return dp[s.size()];
	}
};

int main() {
	Solution st;
	string s = "applepenapple";
	vector<string> wordDict = { "apple", "pen" };
	cout << boolalpha << st.wordBreak(s, wordDict) << noboolalpha << endl;
	return 0;
}