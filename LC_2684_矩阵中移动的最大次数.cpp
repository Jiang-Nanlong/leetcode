//
// Created by ������ on 25-1-10.
//
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

// ����һ�����󣬶���ÿ��(i,j)ֻ���ƶ���(i-1,j+1),(i,j+1),(i+1,j+1)�е�����һ��������Ҫ���ƶ���λ�õ�ֵ�ϸ�����ƶ�ǰλ�õ�ֵ����������ƶ��������

// ÿ��ֻ���ƶ�һ��λ�ã�����ֻ�������ƶ�����ô�ƶ������������������ڵ����ߵ���
// �������BFS��

class Solution {
public:
    int maxMoves(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();

        unordered_set<int> p, q;
        for (int i = 0; i < m; i++)
            p.insert(i);

        for (int col = 0; col < n - 1; col++) {
            q.clear();
            for (int row: p) {
                for (int i = row - 1; i <= row + 1; i++) {
                    if (i >= 0 && i < m && grid[row][col] < grid[i][col + 1])
                        q.insert(i);
                }
            }
            if (q.empty())
                return col;

            p.swap(q);
        }
        return n - 1;
    }
};

int main() {
    Solution st;
    vector<vector<int> > grid{{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    cout << st.maxMoves(grid) << endl;
    return 0;
}
