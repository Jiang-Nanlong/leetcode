#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow = INT_MAX, mincol = INT_MAX, maxrow = INT_MIN,
            maxcol = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    if (i < minrow)
                        minrow = i;
                    if (i > maxrow)
                        maxrow = i;
                    if (j < mincol)
                        mincol = j;
                    if (j > maxcol)
                        maxcol = j;
                }
            }
        }
        return (maxcol - mincol + 1) * (maxrow - minrow + 1);
    }
};

int main() {
    Solution st;
    vector<vector<int>> grid{ {0,1,0},{1,0,1} };
    cout << st.minimumArea(grid) << endl;
    return 0;
}