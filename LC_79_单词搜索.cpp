//
// Created by cml on 25-4-7.
//
#include <iostream>
#include <vector>
#include <functional>
#include <regex>
using namespace std;

class Solution {
public:
    int dir[4][2]{1, 0, 0, 1, -1, 0, 0, -1};

    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        function<bool(int, int, int)> dfs = [&](int x, int y, int i) -> bool {
            if (i == word.size() - 1)
                return true;

            for (int j = 0; j < 4; j++) {
                int nextx = x + dir[j][0];
                int nexty = y + dir[j][1];
                if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n &&
                    !visited[nextx][nexty] && board[nextx][nexty] == word[i + 1]) {
                    visited[nextx][nexty] = true;
                    if (dfs(nextx, nexty, i + 1))
                        return true;
                    visited[nextx][nexty] = false;
                }
            }
            return false;
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(i, j, 0))
                        return true;

                    visited[i][j] = false;
                }
            }
        return false;
    }
};

int main() {
    Solution st;
    vector<vector<char> > board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word{"ABCCED"};
    cout << boolalpha << st.exist(board, word) << noboolalpha << endl;
    return 0;
}
