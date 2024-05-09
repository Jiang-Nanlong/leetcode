#include <iostream>
#include <vector>
using namespace std;

//给定两个字符串，返回使得两个字符串相同所需删除的最小字符数
//第一种方法是按代码随想录的写的，dp[i][j]表示以i-1为结尾的字符串word1，和以j-1为结尾的字符串word2，要想达到相等，所需要删除元素的最小次数
//word1[i - 1] == word2[j - 1]时的递推公式好想，但是不相等时的递推公式有点难想，
// 可以从三个方向过:
// 一是可以删除word1[i-1]，最小操作数是dp[i-1][j]+1;
// 二是可以删除word2[j-1]，最小操作数是dp[i][j-1]+1;
// 三是同时删除word1[i-1]和word2[j-1]，最小操作数是dp[i-1][j-1]+2

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
		for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;
		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}

	//开始我用下边这种方法做的，就是先找出两个字符串中的最长公共子串，然后用两个字符串的个数删去最长公共子串的长度就行
	int minDistance1(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
	}

	// 第二次做，因为这个题只能删除字符，所以计算出两个字符串的最长重复子序列，然后就能计算出要删除的字符数
	int minDistance2(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
	}

	// 优化dp数组
	int minDistance3(string word1, string word2) {
		vector<int> dp(word2.size() + 1, 0);

		for (int i = 1; i <= word1.size(); i++) {
			int prev = 0;
			for (int j = 1; j <= word2.size(); j++) {
				int temp = dp[j];
				if (word1[i - 1] == word2[j - 1])
					dp[j] = prev + 1;
				else
					dp[j] = max(dp[j], dp[j - 1]);
				prev = temp;
			}
		}

		return word1.size() + word2.size() - 2 * dp[word2.size()];
	}

	//pdf上的写法
	int minDistance4(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1,
			vector<int>(word2.size() + 1, 0));

		for (int i = 0; i <= word1.size(); i++)
			dp[i][0] = i;
		for (int i = 0; i <= word2.size(); i++)
			dp[0][i] = i;

		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])  //如果当前元素相同，那么要删除的元素和左上方的一样
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + 2, 
						min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));  //如果当前元素不同，可以有三种情况删除元素来达到相同
			}
		}

		return dp[word1.size()][word2.size()];
	}
};

int main() {
	Solution st;
	string word1 = "leetcode", word2 = "etco";
	cout << st.minDistance(word1, word2) << endl;
	cout << st.minDistance1(word1, word2) << endl;
	return 0;
}