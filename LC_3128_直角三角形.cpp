#include <iostream>
#include <vector>
using namespace std;

// 给定一个二维矩阵，返回grid中3个元素构成的直角三角形的个数，3个元素值都得是1。
// 如果grid中的3个元素满足，一个元素与另一个元素同行，同时与第三个元素同列，就构成直角三角形

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m,0), col(n,0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {  // grid[i][j]作为直角点
                    res += 1LL * (row[i] - 1) * (col[j] - 1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int>> grid{ {1,0,1},{1,0,0},{1,0,0} };
    cout << st.numberOfRightTriangles(grid) << endl;
    return 0;
}