//
// Created by ������ on 25-1-14.
//
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

// ����һ������ͼgrid����������һ����Ԫ����������������ĸ������ƶ�����������ͼ�е���·������Ŀ�������1E9+7ȡ��

// ����dfs+���仯����������
// ÿ��ֻ�������ķ����ƶ���������LC_329_�����е������·����ͬһ���⣬�������ǵ��ƹ�ʽ��һ��
// dp[i][j]��ʾ��grid[i][j]Ϊ��β�ĵ��������е���Ŀ����ʵ���Ǵ��ĸ���������ƶ�����ǰλ�õ����е���·������Ŀ��һ��

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
