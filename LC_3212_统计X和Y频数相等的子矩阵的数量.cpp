#include <iostream>
#include <vector>
using namespace std;

// ����һ����ά����grid��������ֻ��'X','Y','.'������Ԫ�ء��Ӿ���������grid[0][0]��X��YƵ����ͬ�����ٰ���һ��X�������������Ӿ��������

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

                // �ϱߴ�����±ߵ�Ч
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