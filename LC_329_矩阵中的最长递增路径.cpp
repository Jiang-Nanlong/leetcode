//
// Created by 曹孟龙 on 25-1-14.
//
#include <vector>
#include <iostream>
using namespace std;

// 给定一个矩阵，对于每个单元格可以向上下左右四个方向移动，返回最长的递增路径的长度

// 用深度优先搜索，只往单元格元素增大的方向移动，这里用记忆化优化，dp[i][j]表示一个从该位置开始的最长递增路径的长度，如果dp[i][j]已经有值了，说明之前已经遍历过了，直接返回；
// 如果没有值，说明还没有遍历，那么先初始化这个值为1，然后再看看四个方向上的dp值是多少

// 不知道为啥用lambda表达式会比写成一个函数慢好多
class Solution {
    const int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};

    int dfs(vector<vector<int> > &matrix, int i, int j,
            vector<vector<int> > &dp) {
        if (dp[i][j])
            return dp[i][j];

        dp[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int next_i = i + dir[k][0], next_j = j + dir[k][1];
            if (next_i >= 0 && next_i < matrix.size() && next_j >= 0 &&
                next_j < matrix[0].size() &&
                matrix[next_i][next_j] > matrix[i][j])
                dp[i][j] = max(dp[i][j], dfs(matrix, next_i, next_j, dp) + 1);
        }
        return dp[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int> > &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));

        // function<int(int, int)> dfs = [&](int i, int j) {
        //     if (dp[i][j])
        //         return dp[i][j];

        //     dp[i][j] = 1;

        //     for (int k = 0; k < 4; k++) {
        //         int next_i = i + dir[k][0], next_j = j + dir[k][1];
        //         if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n &&
        //             matrix[next_i][next_j] > matrix[i][j])
        //             dp[i][j] = max(dp[i][j], dfs(next_i, next_j) + 1);
        //     }
        //     return dp[i][j];
        // };

        int res = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, dfs(matrix, i, j, dp));

        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int> > matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    cout << st.longestIncreasingPath(matrix) << endl;
    return 0;
}
