#include <iostream>
#include <vector>
using namespace std;

// ����һ�����󣬿��ԴӾ�����κ�һ���ط�����������ֻ�����������ұߺ��±ߣ��������ڣ��������a����b���÷�Ϊb-a�����������÷֡�������һ��
// �������ʵֻ���������ֵ�������ŵ��ֵ֮��Ĳ�ֵ�й�ϵ����·��û��ϵ���������ĳһ����ŵ�(i,j)ֻ��Ҫ�ҳ��������Ϸ��������С�����㼴�ɡ�

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));  // dp[i][j]��ʾ(0,0)��(i,j)֮��ľ����е���Сֵ
        int res = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int temp = INT_MAX;
                if (i > 0)
                    temp = min(temp, dp[i - 1][j]);
                if (j > 0)
                    temp = min(temp, dp[i][j - 1]);
                res = max(res, grid[i][j] - temp);
                dp[i][j] = min(temp, grid[i][j]);  // dp[i][j]ֻ��ȡ��(0,0)��(i-1,j)�������Сֵ��(0,0)��(i,j-1)�������Сֵ��grid[i][j]��ֵ֮���������Сֵ
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