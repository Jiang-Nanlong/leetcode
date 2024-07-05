#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> maxelem(n, INT_MIN);
        vector<pair<int, int>> vec;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (maxelem[j] < matrix[i][j])
                    maxelem[j] = matrix[i][j];

                if (matrix[i][j] == -1) {
                    vec.push_back({ i,j });
                }
            }
        }

        for (auto p : vec) {
            matrix[p.first][p.second] = maxelem[p.second];
        }
        return matrix;
    }
};

int main() {
    Solution st;
    vector<vector<int>> matrix{ {1,2,-1},{4,-1,6},{7,8,9} };
    vector<vector<int>> res = st.modifiedMatrix(matrix);
    for (auto r : res) {
        for (auto i : r)
            cout << i << " ";
        cout << endl;
    }

}