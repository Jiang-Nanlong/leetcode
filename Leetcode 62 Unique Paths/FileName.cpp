
/*
* 机器人位于m*n网络的左上角，只能向右或者向下移动，到达网络的右下角结束，问一共有多少条路径
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) dp[i][0] = 1;
		for (int j = 0; j < n; j++)dp[0][j] = 1;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main() {
	Solution s = Solution();
	int num = s.uniquePaths(7, 3);
	cout << num << endl;
	return 0;
}