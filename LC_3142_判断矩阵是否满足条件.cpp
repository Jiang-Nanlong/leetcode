#include <iostream>
#include <vector>
using namespace std;

// 如果grid[i][j]下方的格子存在，且grid[i][j] == grid[i+1][j]
// 如果grid[i][j]右方的格子存在，且grid[i][j] != grid[i][j+1]，如果矩阵中的所有点都满足这个条件，返回true，否则返回false

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i != grid.size() - 1 && grid[i][j] != grid[i + 1][j])
                    return false;
                if (j != grid[0].size() - 1 && grid[i][j] == grid[i][j + 1])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution st;
    vector<vector<int>>grid{ {1, 0, 2},{1, 0, 2} };
    cout << boolalpha << st.satisfiesConditions(grid) << noboolalpha << endl;
    return 0;
}