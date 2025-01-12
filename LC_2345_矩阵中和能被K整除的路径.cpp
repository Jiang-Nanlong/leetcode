//
// Created by 曹孟龙 on 25-1-12.
//
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

// 给定一个m*n的矩阵和一个整数k，最初从(0,0)出发，只能向右或向下，最终到达(m-1,n-1)，返回路径和能被k整除的路径数

// 这个题和余数有关，因此把二维dp数组多加一维，dp[i][j][v]表示到达(i,j)处，余数为v的路径数
// 因此递推公式为dp[i + 1][j + 1][(v + grid[i][j]) % k] =dp[i][j + 1][v]+dp [i + 1][j][v]
// 初始状态dp[0][0][grid[0][0]%k]=1

// 这里为了方便初始化，把dp的前两维变为m+1和n+1，这样初始条件就变为dp[0][1][0]=1或者dp[1][0][0]=1，这里有点难想。
// 左上角第一个元素对应的dp[1][1][grid[0][0]%k]=1，相当于把递推公式中的i=0，j=0,v=0，然后就可以确定初始条件。

class Solution {
    const int MOD = 1e9 + 7;

public:
    int numberOfPaths(vector<vector<int> > &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dp[m + 1][n + 1][k];
        memset(dp, 0, sizeof(dp));
        dp[1][0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int v = 0; v < k; v++) {
                    dp[i + 1][j + 1][(v + grid[i][j]) % k] =
                            (dp[i][j + 1][v] + dp[i + 1][j][v]) % MOD;
                }
            }
        }
        return dp[m][n][0];
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid{{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    int k = 3;
    cout << st.numberOfPaths(grid, k) << endl;
    return 0;
}
