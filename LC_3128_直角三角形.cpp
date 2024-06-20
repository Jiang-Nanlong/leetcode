#include <iostream>
#include <vector>
using namespace std;

// ����һ����ά���󣬷���grid��3��Ԫ�ع��ɵ�ֱ�������εĸ�����3��Ԫ��ֵ������1��
// ���grid�е�3��Ԫ�����㣬һ��Ԫ������һ��Ԫ��ͬ�У�ͬʱ�������Ԫ��ͬ�У��͹���ֱ��������

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
                if (grid[i][j]) {  // grid[i][j]��Ϊֱ�ǵ�
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