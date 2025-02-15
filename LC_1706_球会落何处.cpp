//
// Created by cml on 25-2-15.
//

// 给定一个二维数组grid有n列，每一列最上边有一个球，grid中的1表示球从该位置会滚到右下，-1表示球会从该位置滚到左下，
// 如果球在滚的过程中碰到了墙壁，或者两个球撞到了一起，呈V字形，那么就都会卡住，最后返回一个整数数组，数组中的每一个元素表示最初该位置的球最终落在哪个位置

// 两个球撞到一起的情况比较难想，左边的球值为1，右边球的位置为-1，这种情况下，两个球再动就会碰到一起，也就是1右边为-1，-1左边为1时，会撞
// grid[i][cur_col] != next时


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int> > &grid) {
        int n = grid[0].size(), m = grid.size();
        vector<int> res(n);
        for (int j = 0; j < n; j++) {
            int cur_col = j;
            for (int i = 0; i < m; i++) {
                int next = grid[i][cur_col];
                cur_col += next;
                if (cur_col < 0 || cur_col == n || grid[i][cur_col] != next) {
                    cur_col = -1;
                    break;
                }
            }
            res[j] = cur_col;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid = {
        {1, 1, 1, -1, -1},
        {1, 1, 1, -1, -1},
        {-1, -1, -1, 1, 1},
        {1, 1, 1, 1, -1},
        {-1, -1, -1, -1, -1}
    };
    vector<int> res = st.findBall(grid);
    for (int i: res)
        cout << i << " ";
    cout << endl;
    return 0;
}
