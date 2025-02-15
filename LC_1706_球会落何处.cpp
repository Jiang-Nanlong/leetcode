//
// Created by cml on 25-2-15.
//

// ����һ����ά����grid��n�У�ÿһ�����ϱ���һ����grid�е�1��ʾ��Ӹ�λ�û�������£�-1��ʾ���Ӹ�λ�ù������£�
// ������ڹ��Ĺ�����������ǽ�ڣ�����������ײ����һ�𣬳�V���Σ���ô�Ͷ��Ῠס����󷵻�һ���������飬�����е�ÿһ��Ԫ�ر�ʾ�����λ�õ������������ĸ�λ��

// ������ײ��һ�������Ƚ����룬��ߵ���ֵΪ1���ұ����λ��Ϊ-1����������£��������ٶ��ͻ�����һ��Ҳ����1�ұ�Ϊ-1��-1���Ϊ1ʱ����ײ
// grid[i][cur_col] != nextʱ


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
