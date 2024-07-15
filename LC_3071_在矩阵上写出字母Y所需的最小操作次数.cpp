#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> num_Y(3, 0), num_not_Y(3, 0);
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1)
                    num_Y[grid[i][j]]++;
                else
                    num_not_Y[grid[i][j]]++;
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == n / 2)
                    num_Y[grid[i][j]]++;
                else
                    num_not_Y[grid[i][j]]++;
            }
        }
        vector<int> temp1(3), temp2(3);
        temp1[0] = num_Y[0] + num_Y[1];
        temp1[1] = num_Y[1] + num_Y[2];
        temp1[2] = num_Y[0] + num_Y[2];

        temp2[0] = num_not_Y[0] + num_not_Y[1];
        temp2[1] = num_not_Y[1] + num_not_Y[2];
        temp2[2] = num_not_Y[0] + num_not_Y[2];

        int res = INT_MAX;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j)
                    res = min(res, temp1[i] + temp2[j]);
        return res;
    }
};

int main() {
    Solution st;
    vector<vector<int>> grid{ {2,2,0,0,2},{2,1,1,1,2},{1,0,0,2,1},{2,0,2,0,1},{1,0,2,1,2} };
    cout << st.minimumOperationsToWriteY(grid) << endl;
    return 0;
}