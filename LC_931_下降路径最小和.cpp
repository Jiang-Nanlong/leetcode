/*
给定一个n*n的方阵matrix，找出并返回matrix的下降路径的最小和，可以从第一行的任意一个位置开始，并从每一行中选择一个元素，
但是在选择下一行的元素的时候和当前行所在元素的列数最多相差一列
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		for(int i=0;i<n;i++)
			dp[0][i] = matrix[0][i];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j - 1 >= 0)
					//dp[i][j] = dp[i][j] > dp[i - 1][j - 1] + matrix[i][j] ? dp[i - 1][j - 1] + matrix[i][j] : dp[i][j];
					dp[i][j] = min(dp[i - 1][j - 1] + matrix[i][j], dp[i][j]);
				dp[i][j] = min(dp[i - 1][j] + matrix[i][j], dp[i][j]);
				if (j + 1 < n)
					dp[i][j] = min(dp[i - 1][j + 1] + matrix[i][j], dp[i][j]);
			}
		}
		int minPath = dp[n - 1][0];
		for (int i = 0; i < n; i++)
			if (minPath > dp[n - 1][i])
				minPath = dp[n - 1][i];
		return minPath;
	}
};
//太牛逼了  第一遍就做出来了，和宫水三叶进阶后的思路一样，太牛逼了，不过好像时间和内存占用的都比较多,把?:换成min以后就快了
int main() {
	vector<vector<int>> dp1 = { {2,1,3},{6,5,4},{7,8,9} };
	vector<vector<int>> dp2 = { {-19,57},{-40,-5} };
	Solution s;
	cout << s.minFallingPathSum(dp1) << endl;
	cout << s.minFallingPathSum(dp2) << endl;
	return 0;
}
