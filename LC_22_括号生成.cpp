//
// Created by cml on 25-4-7.
//

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<int> cnt(2, 0);
        vector<string> res;
        string path(2 * n, ' ');

        function<void(int)> dfs = [&](int i)-> void {
            if (i == 2 * n) {
                res.push_back(path);
                return;
            }
            if (cnt[0] < n && cnt[0] >= cnt[1]) {
                ++cnt[0];
                path[i] = '(';
                dfs(i + 1);
                --cnt[0];
            }
            if (cnt[1] < n && cnt[0] >= cnt[1] + 1) {
                ++cnt[1];
                path[i] = ')';
                dfs(i + 1);
                --cnt[1];
            }
        };
        dfs(0);
        return res;
    }
};

int main() {
    Solution st;
    int n = 3;
    vector<string> res = st.generateParenthesis(n);
    for (auto i: res)
        cout << i << endl;
    return 0;
}
