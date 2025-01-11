//
// Created by ������ on 25-1-11.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ͳ�ƴ����Ͻǵ����½�·���г˻������ֵ��������ֵΪ�������򷵻�-1��������ֻ�����һ������ƶ�

// ��Ϊ��ȷ����ǰλ�õ��������������Ǹ���������Ҫ����ǰһ��λ�õ����ֵ����Сֵ��������Ҫ����dp����

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

    // ����ÿ��λ�õĳ˻������ֵ����Сֵֻ�����ϱ�λ�ú����λ���йأ����Կ����ù�������������
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
