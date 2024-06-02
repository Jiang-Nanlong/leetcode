#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这个题和合并区间还有射箭的那个题一模一样

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), cmp);
        vector<vector<int>> res;
        int leftboard = meetings[0][0], rightboard = meetings[0][1];
        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= rightboard) {
                rightboard = max(rightboard, meetings[i][1]);
            }
            else {
                res.push_back({ leftboard,rightboard });
                leftboard = meetings[i][0];
                rightboard = meetings[i][1];
            }
        }
        res.push_back({ leftboard, rightboard });

        int count = 0;
        for (int i = 0; i < res.size(); i++) {
            if (i == 0) {
                count += res[i][0] - 1;
            }
            else {
                count += (res[i][0] - res[i - 1][1] - 1);
            }
        }
        count += (days - res[res.size() - 1][1]);
        return count;
    }
};

int main() {
    Solution st;
    int days = 10;
    vector<vector<int>> meetings{ {5, 7},{1, 3},{9, 10} };
    int res = st.countDays(days, meetings);
    cout << res << endl;
    return 0;
}