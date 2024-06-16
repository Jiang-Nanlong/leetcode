#include <iostream>
#include <vector>
using namespace std;

// 给定一个矩阵，可以从矩阵的任何一个地方起跳，但是只能跳到它的右边和下边（不必相邻），比如从a跳到b，得分为b-a。求最后的最大得分。至少跳一次
// 这个题其实只和起跳点的值和最后落脚点的值之间的差值有关系，和路径没关系。所以针对某一个落脚点(i,j)只需要找出它的左上方矩阵的最小起跳点即可。

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));  // dp[i][j]表示(0,0)到(i,j)之间的矩阵中的最小值
        int res = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int temp = INT_MAX;
                if (i > 0)
                    temp = min(temp, dp[i - 1][j]);
                if (j > 0)
                    temp = min(temp, dp[i][j - 1]);
                res = max(res, grid[i][j] - temp);
                dp[i][j] = min(temp, grid[i][j]);  // dp[i][j]只能取以(0,0)到(i-1,j)矩阵的最小值和(0,0)到(i,j-1)矩阵的最小值和grid[i][j]的值之间的最最最小值
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int>> grid = { {9, 5, 7, 3}, {8, 9, 6, 1}, {6, 7, 14, 3}, {2, 5, 3, 1} };
    cout << st.maxScore(grid) << endl;
    return 0;
}