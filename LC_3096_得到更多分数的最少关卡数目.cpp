#include <iostream>
#include <vector>
using namespace std;

// A和B两个人玩游戏，A从0开始走，如果遇到1，得分就加1；如果遇到0，得分就减1.A走到一个关卡后，B走完剩下的，计分规则一样。
// 问A得分比B高，至少要完成多少关。而且每人至少要完成一个关卡。
// 所有的关卡加一起，总的得分是固定的，用总得分减去A的得分就是B的得分。
// 只要A的得分 > 总分-A的得分即可。
// 另外A不能走到第n关，最多走到n-1关，因为B至少走一关。

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> pre_sum(n, 0);
        pre_sum[0] = possible[0] == 1 ? 1 : -1;

        for (int i = 1; i < n; i++) {
            if (possible[i] == 1)
                pre_sum[i] = pre_sum[i - 1] + 1;
            else
                pre_sum[i] = pre_sum[i - 1] - 1;
        }
        int sum = pre_sum[n - 1];
        for (int i = 0; i < n; i++) {
            if (pre_sum[i] > sum - pre_sum[i] && i != n - 1)
                return i + 1;
        }
        return -1;
    }
};

int main() {
    Solution st;
    vector<int> possible{ 1,0,1,0 };
    cout << st.minimumLevels(possible) << endl;
    return 0;
}