//
// Created by ������ on 25-1-10.
//
#include <vector>
#include <iostream>
using namespace std;

// �������ʵ�����ñ��������ǻ���һ��dp������ֱ����ԭ������Ϊdp���飬���ǲ��ܴ������±�������ΪmoveCast�����������grid�����Ԫ��ֵ�йأ�����������±����Ļ����޸ĵ�ǰ�е�Ԫ��ֵ������һ��ʱ�ᱨ������ֻ�ܴ������ϱ���

class Solution {
public:
    int minPathCost(vector<vector<int> > &grid, vector<vector<int> > &moveCost) {
        int m = grid.size(), n = grid[0].size();
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int mincost = INT_MAX;
                // �����dp[i][j], ����һ�еĵ�k��Ԫ�ع����������Ǵ�dp[i+1][k]->dp[i][j]
                for (int k = 0; k < n; k++) {
                    mincost = min(mincost, grid[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                grid[i][j] += mincost;
            }
        }
        int res = INT_MAX;
        for (int i: grid[0])
            res = min(res, i);

        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid{{5, 3}, {4, 0}, {2, 1}};
    vector<vector<int> > moveCast{{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
    cout << st.minPathCost(grid, moveCast) << endl;
    return 0;
}
