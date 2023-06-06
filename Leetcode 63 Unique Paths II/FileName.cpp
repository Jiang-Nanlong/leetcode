/**
* 同62题，从网格的左上角到网格的右下角有多少种路径，过程中只能右移或下移，但是网格中会有障碍物
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
				
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (obstacleGrid[i][j] != 1) {
					if (i > 0 && j > 0)
						dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
					else if (i > 0)
						dp[i][j] = dp[i - 1][j];
					else if (j > 0)
						dp[i][j] = dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main() {
	vector<vector<int>> grid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
	Solution s = Solution();
	int num = s.uniquePathWithObstacles(grid);
	cout << num << endl;

	return 0;
}