#include <iostream>
#include <vector>
using namespace std;

// 给定一个二维矩阵grid，矩阵中只有'X','Y','.'，三种元素。子矩阵必须包含grid[0][0]，X和Y频数相同，至少包含一个X。返回这样的子矩阵的数量

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> count_x(m + 1, vector<int>(n + 1));
        vector<vector<int>> count_y(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                /*
                if (grid[i][j] == 'X')
                    count_x[i + 1][j + 1] = count_x[i + 1][j] +
                    count_x[i][j + 1] - count_x[i][j] +
                    1;
                else
                    count_x[i + 1][j + 1] = count_x[i + 1][j] +
                    count_x[i][j + 1] - count_x[i][j];
                if (grid[i][j] == 'Y')
                    count_y[i + 1][j + 1] = count_y[i + 1][j] +
                    count_y[i][j + 1] - count_y[i][j] +
                    1;
                else
                    count_y[i + 1][j + 1] = count_y[i + 1][j] +
                    count_y[i][j + 1] - count_y[i][j];
                */

                // 上边代码和下边等效
                count_x[i + 1][j + 1] = count_x[i + 1][j] + count_x[i][j + 1] - count_x[i][j] + (grid[i][j] == 'X');
                count_y[i + 1][j + 1] = count_y[i + 1][j] + count_y[i][j + 1] - count_y[i][j] + (grid[i][j] == 'Y');
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (count_x[i][j] > 0 && count_x[i][j] == count_y[i][j])
                    res++;
        return res;
    }
};

int main() {
    Solution st;
    vector<vector<char>> grid{ {'X','Y','.'},{'Y','.','.'} };
    cout << st.numberOfSubmatrices(grid) << endl;
    return 0;
}