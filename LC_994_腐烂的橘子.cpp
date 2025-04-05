//
// Created by cml on 25-4-5.
//
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int> > que;
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    que.push(make_pair(i, j));
                else if (grid[i][j] == 1)
                    ++count;

        int res = 0;
        int dir[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
        while (!que.empty() && count > 0) {
            ++res;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = que.front();
                que.pop();
                for (int j = 0; j < 4; j++) {
                    int next_x = x + dir[j][0];
                    int next_y = y + dir[j][1];
                    if (next_x >= 0 && next_x < m && next_y >= 0 &&
                        next_y < n && grid[next_x][next_y] == 1) {
                        --count;
                        grid[next_x][next_y] = 2;
                        que.push(make_pair(next_x, next_y));
                    }
                }
            }
        }
        if (!count)
            return res;
        return -1;
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << Solution().orangesRotting(grid) << endl;
    return 0;
}
