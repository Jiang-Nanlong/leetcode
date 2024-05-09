#include <iostream>
#include <vector>
using namespace std;

//给定两个字符串word1和word2，返回把word1变成word2的最小操作数，可以插入字符，删除字符，替换字符。
//这个题的dp数组和初始化还有word1[i - 1] == word2[j - 1]的递推公式都挺好想。
//就是word1[i - 1] != word2[j - 1]时的递推公式，我只想出了dp[i - 1][j - 1] + 1和dp[i - 1][j] + 1，没想到dp[i][j-1]+1，因为觉得只能修改word1，不应该修改word2
//而dp[i][j-1]+1就是在word2的基础上修改，但是后来看了视频才明白，word2添加元素相当于word1删除一个元素，word2删除一个元素相当于word1添加一个元素，具体可以想象word1：ab  word2：a
//所以在word1[i - 1] != word2[j - 1]时，分为三种情况：
//0.word1添加或删除一个元素变成word2，即dp[i-1][j]+1；
//1.word2添加或删除一个元素变成word2，即dp[i][j-1]+1；
//2.word1修改一个元素变成word2，即dp[i-1][j-1]+1;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;
		for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;

		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}

	//第二次做，还是不会，这个题不相同时的递推公式真难想
	// dp[i-1][j-1]+1表示替换一个当前元素
	// dp[i - 1][j] + 1, dp[i][j - 1] + 1分别表示删除word1中的当前元素和删除word2中当前元素
	int minDistance1(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word1.size(); i++)
			dp[i][0] = i;
		for (int i = 0; i <= word2.size(); i++)
			dp[0][i] = i;

		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
		return dp[word1.size()][word2.size()];
	}
};

int main() {
	Solution st;
	string word1 = "horse", word2 = "ros";
	cout << st.minDistance(word1, word2) << endl;
	return 0;
}