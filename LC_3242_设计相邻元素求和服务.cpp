#include <iostream>
#include <vector>
using namespace std;

class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        g = vector<vector<int>>(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                g[j][k] = grid[j][k];
            }
        }
    }

    // 求上下左右四个方向的和
    int adjacentSum(int value) {
        int res = 0;
        int row = 0, col = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == value) {
                    row = i;
                    col = j;
                    break;
                }
        if (row - 1 >= 0)
            res += g[row - 1][col];
        if (row + 1 < n)
            res += g[row + 1][col];
        if (col - 1 >= 0)
            res += g[row][col - 1];
        if (col + 1 < n)
            res += g[row][col + 1];
        return res;
    }

    // 求左上，右上，左下，右下四个位置的和
    int diagonalSum(int value) {
        int res = 0;
        int row = 0, col = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == value) {
                    row = i;
                    col = j;
                    break;
                }
        if (row + 1 < n && col + 1 < n)
            res += g[row + 1][col + 1];
        if (row + 1 < n && col - 1 >= 0)
            res += g[row + 1][col - 1];
        if (row - 1 >= 0 && col + 1 < n)
            res += g[row - 1][col + 1];
        if (row - 1 >= 0 && col - 1 >= 0)
            res += g[row - 1][col - 1];
        return res;
    }

private:
    int n;
    vector<vector<int>> g;
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

int main() {
    vector<vector<int>> grid{ {0, 1, 2},{3,4,5},{6,7,8} };
    neighborSum st(grid);
    cout << st.adjacentSum(1) << endl;
    cout << st.adjacentSum(4) << endl;
    cout << st.diagonalSum(4) << endl;
    cout << st.diagonalSum(8) << endl;

    return 0;
}