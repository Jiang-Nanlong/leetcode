#include <iostream>
#include <vector>
using namespace std;

//找出两个数组中最长公共子序列的长度，子序列中的字母不一定是连续的。
//开始我以为是LeetCode 300和718两个题结合，但是后来发现递推公式写不了。
//这个题的dp数组和含义还是比较好想
//这个题的递推公式比较难想

class Solution {
public:
	//这个是按代码随想录的代码写得，方便初始化
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
		for (int i = 1; i <= text1.size(); i++) {
			for (int j = 1; j <= text2.size(); j++) {
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[text1.size()][text2.size()];
	}

	//这是自己写的，初始化麻烦了一点，但是看起来思路更清晰
	int longestCommonSubsequence1(string text1, string text2) {
		vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
		if (text1[0] == text2[0]) dp[0][0] = 1;  //这一句是为了防止第一个字母不一样，在下边两个初始化的时候i从0开始会出现数组越界的问题

		for (int i = 1; i < text1.size(); i++) {
			if (text1[i] == text2[0]) dp[i][0] = 1;
			else dp[i][0] = dp[i - 1][0];
		}
		for (int i = 1; i < text2.size(); i++) {
			if (text1[0] == text2[i]) dp[0][i] = 1;
			else dp[0][i] = dp[0][i - 1];
		}

		for (int i = 1; i < text1.size(); i++) {
			for (int j = 1; j < text2.size(); j++) {
				if (text1[i] == text2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[text1.size() - 1][text2.size() - 1];
	}

	//第二次做，居然自己做出来了，太牛了
	int longestCommonSubsequence2(string text1, string text2) {
		vector<vector<int>>dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

		for (int i = 1; i <= text1.size(); i++) {
			for (int j = 1; j <= text2.size(); j++) {
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[text1.size()][text2.size()];
	}

	//优化为一维数组
	int longestCommonSubsequence3(string text1, string text2) {
		vector<int> dp(text2.size() + 1, 0);

		for (int i = 1; i <= text1.size(); i++) {
			int prev = 0;
			for (int j = 1; j <= text2.size(); j++) {
				int temp = dp[j];
				if (text1[i - 1] == text2[j - 1]) {
					//注意看二维数组的时候，如果当前元素相同，那么要从左上方[i-1][j-1]+1得到当前值，
					// 但是内层循环从前往后遍历，会覆盖左上方的值，也就是dp数组中的前一个位置，所以要用prev保存前一个dp值
					dp[j] = prev + 1;
				}
				else {
					dp[j] = max(dp[j], dp[j - 1]);
				}
				prev = temp;
			}
		}
		return dp[text2.size()];
	}
};

int main() {
	Solution st;
	string text1 = "abc", text2 = "def";
	cout << st.longestCommonSubsequence(text1, text2) << endl;
	cout << st.longestCommonSubsequence1(text1, text2) << endl;
	return 0;
}