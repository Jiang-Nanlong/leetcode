#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 感觉这个题更像贪心，优先切开销较大的

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(),
            [](int& a, int& b) { return a > b; });
        sort(verticalCut.begin(), verticalCut.end(),
            [](int& a, int& b) { return a > b; });

        int h = 1, v = 1;
        int res = 0;
        int i = 0, j = 0;
        while (i < m - 1 && j < n - 1) {
            if (horizontalCut[i] > verticalCut[j]) {
                res += horizontalCut[i] * v;
                h++;
                i++;
            }
            else {
                res += verticalCut[j] * h;
                v++;
                j++;
            }
        }
        while (i < m - 1) {
            res += horizontalCut[i] * v;
            i++;
        }
        while (j < n - 1) {
            res += verticalCut[j] * h;
            j++;
        }
        return res;
    }
};

int main() {
    Solution st;
    int m = 6, n = 3;
    vector<int> horizontalCut{ 2,3,2,3,1 }, verticalCut{ 1,2 };
    cout << st.minimumCost(m, n, horizontalCut, verticalCut) << endl;
    return 0;
}