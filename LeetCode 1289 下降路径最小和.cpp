/*
和931题差不多，给定一个n*n的矩阵，返回从矩阵中的第一行中的任意一个元素到达最下边一行的路径最小值，但是下一行元素不能与当前行元素在同一列
*/
#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int minFallingPathSum(vector<vector<int>>& grid) {
//		int n = grid.size();
//		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//		for (int i = 0; i < n; i++)
//			dp[0][i] = grid[0][i];
//		for (int i = 1; i < n; i++) {  //每一行
//			for (int j = 0; j < n; j++) {  //每一列
//				for (int k = 0; k < n; k++) {
//					if (j == k) continue;
//					dp[i][j] = min(dp[i][j], dp[i - 1][k] + grid[i][j]);
//				}
//			}
//		}
//
//		int minPath = dp[n - 1][0];
//		for (int i = 0; i < n; i++)
//			minPath = min(minPath, dp[n - 1][i]);
//		return minPath;
//	}
//};
//虽然做出来了，但是时间复杂度有点大O(n^3)
//好吧，答案给的也是这样的，不过可以进阶一下降低复杂度
//这个题有一个没注意到的点：当对一行进行动态规划的时候，我是枚举上一行的每一个值，其实不需要枚举每一个，而只要关心最小的两个值就行
//为什么是最小的“两”个值，而不是一个？
//因为当前元素不能与上一行的元素在同一列。

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		//先通过一次遍历获取第一行中最小的两个数
		int j1 = -1, j2 = -1;   //j1指示最小值的列，j2指示次小值的列
		for (int i = 0; i < n; i++) {
			dp[0][i] = grid[0][i];
			if (grid[0][i] < (j1 == -1 ? INT_MAX : grid[0][j1])) {
				j2 = j1;
				j1 = i;
			}
			else if (grid[0][i] < (j2 == -1 ? INT_MAX : grid[0][j2])) {
				j2 = i;
			}
		}

		for (int i = 1; i < n; i++) {
			int ti1 = -1, ti2 = -1;    //ti1指示第i行最小值的列，ti2指示第i行次小值的列
			for (int j = 0; j < n; j++) {
				if (j != j1) {  //如果可以选择最小值所在的列，则选择
					dp[i][j] = dp[i - 1][j1] + grid[i][j];
				}
				else {   //若不能选择最小值所在的列，则选择次小值所在的列
					dp[i][j] = dp[i - 1][j2] + grid[i][j];
				}

				if (dp[i][j] < (ti1 == -1 ? INT_MAX : dp[i][ti1])) {
					ti2 = ti1;
					ti1 = j;
				}
				else if (dp[i][j] < (ti2 == -1 ? INT_MAX : dp[i][ti2])) {
					ti2 = j;
				}
			}
			j1 = ti1;
			j2 = ti2;
		}
		int minPath = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (minPath > dp[n - 1][i])
				minPath = dp[n - 1][i];
		}
		return minPath;
	}
};
//这方法太牛逼了，太简洁了，负责度有了质的飞跃
int main() {
	Solution s;
	vector<vector<int>> matrix1 = { {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> matrix2 = { {7} };
	
	cout << s.minFallingPathSum(matrix1) << endl;
	cout << s.minFallingPathSum(matrix2) << endl;

	return 0;
}