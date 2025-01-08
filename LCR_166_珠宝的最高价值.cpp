//
// Created by 曹孟龙 on 25-1-8.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution {
public:
    int jewelleryValue(vector<vector<int> > &frame) {
        int m = frame.size(), n = frame[0].size();

        for (int i = 1; i < m; i++)
            frame[i][0] += frame[i - 1][0];

        for (int i = 1; i < n; i++)
            frame[0][i] += frame[0][i - 1];

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                frame[i][j] =
                        max(frame[i - 1][j], frame[i][j - 1]) + frame[i][j];

        return frame[m - 1][n - 1];
    }

    // 另一种写法
    int jewelleryValue1(vector<vector<int> > &frame) {
        int m = frame.size(), n = frame[0].size();

        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[i + 1][j + 1] =
                        max(dp[i + 1][j], dp[i][j + 1]) + frame[i][j];

        return dp[m][n];
    }

    // 上边的代码进一步优化。当前行的计算只会用到上一行，所以只需要保存上一行即可，但是又为了避免每个元素都复制一遍，所以可以用二维的dp代替m维dp数组
    int jewelleryValue2(vector<vector<int> > &frame) {
        int m = frame.size(), n = frame[0].size();

        int dp[2][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[(i + 1) % 2][j + 1] =
                        max(dp[(i + 1) % 2][j], dp[i % 2][j + 1]) + frame[i][j];

        return dp[m % 2][n];
    }
};

int main() {
    Solution st;
    vector<vector<int> > frame{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << st.jewelleryValue(frame) << endl;
    return 0;
}
