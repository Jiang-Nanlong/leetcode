#include <iostream>
#include <vector>
using namespace std;

// 给定一个3*3的数组，数组中只有两种类型的元素B或W，B表示黑色，W表示白色。判断在至多改变一个格子颜色的前提下，矩阵中是否存在2*2的颜色相同的正方形
// 其实就是判断4个2*2的数组中的同一种颜色的数量是不是大于等于3，如果是的话就可以修改一个或不修改构造同色正方形

#define GET_COLOR(c) (c-'C'>0?1:0)  // W用1表示，B用0表示

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        char num[2] = { 0 };
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                num[GET_COLOR(grid[i][j])]++;

        if (num[0] >= 3 || num[1] >= 3) return true;
        memset(num, 0, 2);

        for (int i = 0; i < 2; i++)
            for (int j = 1; j < 3; j++)
                num[GET_COLOR(grid[i][j])]++;

        if (num[0] >= 3 || num[1] >= 3) return true;
        memset(num, 0, 2);

        for (int i = 1; i < 3; i++)
            for (int j = 0; j < 2; j++)
                num[GET_COLOR(grid[i][j])]++;

        if (num[0] >= 3 || num[1] >= 3) return true;
        memset(num, 0, 2);

        for (int i = 1; i < 3; i++)
            for (int j = 1; j < 3; j++)
                num[GET_COLOR(grid[i][j])]++;

        if (num[0] >= 3 || num[1] >= 3) return true;

        return false;
    }
};

int main() {
    Solution st;
    vector<vector<char>> grid{ {'B','W','B'},{'B','W','W'} ,{'B','W','B'} };
    cout << boolalpha << st.canMakeSquare(grid) << noboolalpha << endl;
    return 0;
}