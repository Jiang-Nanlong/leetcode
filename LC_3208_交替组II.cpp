#include <iostream>
#include <vector>
using namespace std;

// LeetCode 3208 交替组I的拓展版，用的滑动窗口

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int res = 0;
        int alternatingCount = 0;

        for (int i = 0; i < k - 1; ++i) {
            if (colors[i] != colors[i + 1]) {
                alternatingCount++;
            }
        }
        if (alternatingCount == k - 1) {
            res++;
        }

        for (int i = 1; i < n; ++i) {
            // 移出窗口的元素
            if (colors[i - 1] != colors[(i - 1 + 1) % n]) {
                alternatingCount--;
            }
            // 新进入窗口的元素
            if (colors[(i + k - 2) % n] != colors[(i + k - 1) % n]) {
                alternatingCount++;
            }
            // 判断当前窗口是否是交替组
            if (alternatingCount == k - 1) {
                res++;
            }
        }

        return res;
    }
};

int main() {
    Solution st;
    vector<int> colors{ 0,1,0,1,0 };
    int k = 3;
    cout << st.numberOfAlternatingGroups(colors, k) << endl;
    return 0;
}