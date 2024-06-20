#include <iostream>
#include <vector>
using namespace std;

// ����һ��3*3�����飬������ֻ���������͵�Ԫ��B��W��B��ʾ��ɫ��W��ʾ��ɫ���ж�������ı�һ��������ɫ��ǰ���£��������Ƿ����2*2����ɫ��ͬ��������
// ��ʵ�����ж�4��2*2�������е�ͬһ����ɫ�������ǲ��Ǵ��ڵ���3������ǵĻ��Ϳ����޸�һ�����޸Ĺ���ͬɫ������

#define GET_COLOR(c) (c-'C'>0?1:0)  // W��1��ʾ��B��0��ʾ

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