#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// ����һ�������������а���n���ڵ㣬����0��n-1��˳���ǣ����һ������Ϊn-1�Ķ�ά�����ʾ���еıߡ�
// ���һ���ڵ���������������Ľڵ������ͬ������Ϊ�ý����һ���ýڵ㣬�������кýڵ�ĸ�����

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> grid(n);
        for (auto& e : edges) {
            grid[e[0]].push_back(e[1]);
            grid[e[1]].push_back(e[0]);
        }

        int res = 0;
        function<int(int, int)> dfs = [&](int x, int pre) {
            bool flag = true;
            int precount = -1;
            int size = 1;
            for (int y : grid[x]) {
                if (y == pre)
                    continue;
                int count = dfs(y, x);
                if (precount == -1)
                    precount = count;
                else if (precount != count)
                    flag = false;

                size += count;
            }
            if (flag)
                res++;
            return size;
            };
        dfs(0, -1);
        return res;
    }
};
int main() {
    Solution st;
    vector<vector<int>> edges{ {2,0},{5,0},{4,0},{3,0},{1,0} };
    cout << st.countGoodNodes(edges) << endl;
    return 0;
}