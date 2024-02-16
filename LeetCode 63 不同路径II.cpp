#include <iostream>
#include <vector>
using namespace std;

//这个题和上一个的区别是这一题的二维数组中有障碍物，我开始在想有障碍物会影响到它本身的位置和它右边和下边的位置，该怎么处理这个问题
//后来才想通只要把障碍物位置的dp数组写成0就行，
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) dp[0][i] = 1;
		for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main() {
	Solution st;
	vector<vector<int>> obstacleGrid{ {0,0,0},{0,1,0},{0,0,0} };
	cout << st.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}