#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + grid[i][j];
                if (dp[i + 1][j + 1] <= k)
                    res++;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int>> grid{ {7,6,3},{6,6,1} };
    int k = 18;
    cout << st.countSubmatrices(grid, k) << endl;
    return 0;
}