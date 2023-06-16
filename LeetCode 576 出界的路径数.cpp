/*
����һ��m*n�����飬�����һ�����������ڵ�һ����(startRow,startColumn)�����������ڵ��ĸ��������ƶ�������һ������maxMove��ʾ������ƶ�maxMove�Σ�
���ؽ����Ƴ��߽��·���������𰸿��ܷǳ��󣬷��ض�1000000007ȡ���Ľ��
*/
#include<iostream>
#include <vector>
using namespace std;

//�ʼ�뵽����֮ǰ�����⣬ͨ��dfs���ص����������⣬�����Ҳ����ͨ��dfsһ��һ�����ƶ�����������ڵ�����(row,col),
//row == 0��˵�����Դ��ϱ߳���
//col == 0��˵�����Դ���߳���
//row == m - 1��˵�����Դ��±߳���
//col == n - 1��˵�����Դ��ұ߳��磬
//˳��Ūһ����ά���飬��¼����ÿһ�㴦��ʣ��Ĳ����� ������ô�Ļ����о��ռ临�Ӷ�̫����
//���԰�����(row,col)����һ����index = row * n + col����������ͳ���ά����,dp[index][maxMove]��ʾ�ӵ�index��ʼ�����maxMove�߳������·������

//��ʵ֤����������˼·���Ǻ������һ�����������Լ�û��д�������Ĵ��룬���Ǹо��������ֳɾ͸У���

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
		//�±���ôд�Ļ�����ʱ��ᷢ��intԽ�����
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