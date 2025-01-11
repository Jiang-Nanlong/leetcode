//
// Created by 曹孟龙 on 25-1-11.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 统计从左上角到右下角路径中乘积的最大值，如果最大值为负数，则返回-1。过程中只能向右或向下移动

// 因为不确定当前位置的数字是正数还是负数，所以要保留前一个位置的最大值和最小值，所以需要两个dp数组

class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;

public:
    int maxProductPath(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<ll> > max_dp(m, vector<ll>(n, INT_MIN));
        vector<vector<ll> > min_dp(m, vector<ll>(n, INT_MAX));

        max_dp[0][0] = min_dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0) {
                    ll a = max_dp[i - 1][j] * grid[i][j];
                    ll b = min_dp[i - 1][j] * grid[i][j];
                    max_dp[i][j] = max({a, b, max_dp[i][j]});
                    min_dp[i][j] = min({a, b, min_dp[i][j]});
                }
                if (j - 1 >= 0) {
                    ll a = max_dp[i][j - 1] * grid[i][j];
                    ll b = min_dp[i][j - 1] * grid[i][j];
                    max_dp[i][j] = max({a, b, max_dp[i][j]});
                    min_dp[i][j] = min({a, b, min_dp[i][j]});
                }
            }
        }
        return max(max_dp[m - 1][n - 1], min_dp[m - 1][n - 1]) < 0
                   ? -1
                   : max(max_dp[m - 1][n - 1], min_dp[m - 1][n - 1]) % MOD;
    }

    // 对于每个位置的乘积的最大值和最小值只和它上边位置和左边位置有关，所以可以用滚动数组代替矩阵
    int maxProductPath1(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<ll> max_dp(n);
        vector<ll> min_dp(n);

        max_dp[0] = min_dp[0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            max_dp[i] = max_dp[i - 1] * grid[0][i];
            min_dp[i] = max_dp[i];
        }
        for (int i = 1; i < m; i++) {
            max_dp[0] *= grid[i][0];
            min_dp[0] *= grid[i][0];

            for (int j = 1; j < n; j++) {
                ll a = max_dp[j - 1] * grid[i][j];
                ll b = min_dp[j - 1] * grid[i][j];
                ll c = max_dp[j] * grid[i][j];
                ll d = min_dp[j] * grid[i][j];
                max_dp[j] = max({a, b, c, d});
                min_dp[j] = min({a, b, c, d});
            }
        }

        return max(max_dp[n - 1], min_dp[n - 1]) < 0
                   ? -1
                   : max(max_dp[n - 1], min_dp[n - 1]) % MOD;
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid{{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};
    cout << st.maxProductPath(grid) << endl;
    return 0;
}
