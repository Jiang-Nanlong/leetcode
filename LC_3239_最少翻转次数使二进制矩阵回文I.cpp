#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minrow = 0, mincol = 0;
        for (int i = 0; i < m; i++) {
            int j = 0, k = n - 1;
            while (j <= k) {
                if (grid[i][j++] != grid[i][k--])
                    minrow++;
            }
        }

        for (int i = 0; i < n; i++) {
            int j = 0, k = m - 1;
            while (j <= k) {
                if (grid[j++][i] != grid[k--][i])
                    mincol++;
            }
        }
        return min(minrow, mincol);
    }
};

int main() {
    Solution st;
    vector<vector<int>> grid{ {1,0,0},{0,0,0},{0,0,1} };
    cout << st.minFlips(grid) << endl;
    return 0;
}