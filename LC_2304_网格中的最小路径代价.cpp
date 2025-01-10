//
// Created by 曹孟龙 on 25-1-10.
//
#include <vector>
#include <iostream>
using namespace std;

// 这个题其实就是用暴力，但是还有一点dp，可以直接用原数组作为dp数组，但是不能从上往下遍历，因为moveCast数组的索引和grid数组的元素值有关，如果从上往下遍历的话会修改当前行的元素值，在下一行时会报错，所以只能从下往上遍历

class Solution {
public:
    int minPathCost(vector<vector<int> > &grid, vector<vector<int> > &moveCost) {
        int m = grid.size(), n = grid[0].size();
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int mincost = INT_MAX;
                // 求的是dp[i][j], 从下一行的第k个元素过来，所以是从dp[i+1][k]->dp[i][j]
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
