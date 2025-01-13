//
// Created by 曹孟龙 on 25-1-13.
//
#include <vector>
#include <iostream>
using namespace std;

// 给定一个矩阵，矩阵中的每个元素表示到达该位置后血量变化的数量，最初从左上角出发，要到达右下角，只能向右或向下走，如果某个位置的血量变为0或0以下，就会立即死亡。问最初最少需要多少血量可以到右下角？

// 可以倒着想，从右下角出来以后的血量为1，所以可以把dp[i][j]表示刚到达dungeon[i][j]时最初的血量，为了方便设置初始状态，可以把dp数组设为m+1*n+1维的，所以初始状态就变为dp[m][n-1]=dp[m-1][n]=1
// 对于某个位置，它可以从它的右边过来或者下边，只需要关注最小的那个就行，因为只保证有路可以走通就行，不用都得走通。如果从后往前走到(i,j)以后，发现血量<=0，说明这时候的血量得为1，因为要保证活着

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int val = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(val - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution st;
    vector<vector<int> > dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << st.calculateMinimumHP(dungeon) << endl;

    return 0;
}
