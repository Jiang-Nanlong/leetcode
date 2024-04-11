#include <iostream>
#include <vector>
using namespace std;

//这个题和上一个的区别是这一题的二维数组中有障碍物，我开始在想有障碍物会影响到它本身的位置和它右边和下边的位置，该怎么处理这个问题
//后来才想通只要把障碍物位置的dp数组写成0就行，
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++) dp[0][i] = 1;
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    //第二次做
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        bool flag = false;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1)
                flag = true;
            if (flag) dp[i][0] = 0;
        }

        flag = false;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1)
                flag = true;
            if (flag) dp[0][i] = 0;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    //优化dp数组以后的
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                dp[i] = 1;
            else if (obstacleGrid[0][i] == 1)
                dp[i] = 0;
            else
                dp[i] = dp[i - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //这个循环里边不用考虑第0个位置是什么，第0个位置直接由上一个位置滚动过来，这里只需要判断是不是障碍物或者是不是第0个元素就行
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if (j != 0)
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution st;
    vector<vector<int>> obstacleGrid{ {0,0,0},{0,1,0},{0,0,0} };
    cout << st.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}