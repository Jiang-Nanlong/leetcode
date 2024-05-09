/*
给定一个m*n的数组，起初有一个球在数组内的一个点(startRow,startColumn)，可以在相邻的四个方向上移动，给定一个整数maxMove表示球最多移动maxMove次，
返回将球移出边界的路径数量。答案可能非常大，返回对1000000007取余后的结果
*/
#include<iostream>
#include <vector>
using namespace std;

//最开始想到的是之前做的题，通过dfs返回岛屿数量的题，这个题也可以通过dfs一步一步的移动球，如果球所在的坐标(row,col),
//row == 0，说明可以从上边出界
//col == 0，说明可以从左边出界
//row == m - 1，说明可以从下边出界
//col == n - 1，说明可以从右边出界，
//顺便弄一个三维数组，记录球在每一点处的剩余的步数。 但是这么的话，感觉空间复杂度太大了
//可以把坐标(row,col)换成一个数index = row * n + col，这样数组就成两维的了,dp[index][maxMove]表示从点index开始最多走maxMove走出数组的路径条数

//事实证明，这个题的思路就是和我想的一样，但是我自己没有写出完整的代码，还是感觉不到那种成就感，嚓

class Solution {
public:
	int mod = pow(10, 9) + 7;
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		vector<vector<int>> dp(m * n, vector<int>(maxMove + 1, -1));
		return this->dfs(m, n, maxMove, startRow, startColumn, dp);
	}

	int dfs(int m, int n, int maxMove, int startRow, int startCol, vector<vector<int>>& dp) {
		if (startRow < 0 || startRow >= m || startCol < 0 || startCol >= n) return 1;
		if (maxMove == 0) return 0;

		int index = startRow * n + startCol;
		if (dp[index][maxMove] != -1) 
			return dp[index][maxMove];
		//下边这么写的话，有时候会发生int越界错误。他妈的，下次再越界直接longlong
		//int res = (dfs(m, n, maxMove - 1, startRow + 1, startCol, dp) +
		//	dfs(m, n, maxMove - 1, startRow - 1, startCol, dp) +
		//	dfs(m, n, maxMove - 1, startRow, startCol + 1, dp) +
		//	dfs(m, n, maxMove - 1, startRow, startCol - 1, dp)) % mod;
		//dp[index][maxMove] = res;
		//return res;
		long long res1 = dfs(m, n, maxMove - 1, startRow + 1, startCol, dp) % mod;
		long long res2 = dfs(m, n, maxMove - 1, startRow - 1, startCol, dp) % mod;
		long long res3 = dfs(m, n, maxMove - 1, startRow, startCol + 1, dp) % mod;
		long long res4 = dfs(m, n, maxMove - 1, startRow, startCol - 1, dp) % mod;
		dp[index][maxMove] = (res1 + res2 + res3 + res4) % mod;
		return (res1 + res2 + res3 + res4) % mod;
	}
};

int main() {
	int m1 = 2, n1 = 2, maxMove1 = 2, startRow1 = 0, startColumn1 = 0;
	int m2 = 1, n2 = 3, maxMove2 = 3, startRow2 = 0, startColumn2 = 1;
	int m3 = 8, n3 = 50, maxMove3 = 23, startRow3 = 5, startColumn3 = 26;
	Solution s;
	cout << s.findPaths(m1, n1, maxMove1, startRow1, startColumn1) << endl;
	cout << s.findPaths(m2, n2, maxMove2, startRow2, startColumn2) << endl;
	cout << s.findPaths(m3, n3, maxMove3, startRow3, startColumn3) << endl;
	return 0;
}
