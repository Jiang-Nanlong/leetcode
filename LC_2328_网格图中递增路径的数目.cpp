//
// Created by 曹孟龙 on 25-1-14.
//
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

// 给定一个网格图grid，对于任意一个单元格可以往上下左右四个方向移动，返回网格图中递增路径的数目，结果对1E9+7取余

// 还是dfs+记忆化搜索的问题
// 每次只往递增的方向移动，这个题和LC_329_矩阵中的最长递增路径是同一种题，不过就是递推公式不一样
// dp[i][j]表示以grid[i][j]为结尾的递增子序列的数目，其实就是从四个方向可以移动到当前位置的所有递增路径的数目加一起

class Solution {
    const int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};
    const int MOD = 1e9 + 7;

public:
    int countPaths(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int> > dp(m, vector<int>(n, 0));

        function<int(int, int)> dfs = [&](int x, int y) {
            if (dp[x][y])
                return dp[x][y];

            dp[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int next_x = x + dir[i][0], next_y = y + dir[i][1];
                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n &&
                    grid[next_x][next_y] < grid[x][y]) {
                    int temp = dfs(next_x, next_y) % MOD;
                    dp[x][y] = (dp[x][y] + temp) % MOD;
                }
            }
            return dp[x][y];
        };

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                res = (res + dfs(i, j)) % MOD;
        }

        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid{{1, 1}, {3, 4}};
    cout << st.countPaths(grid) << endl;
    return 0;
}
