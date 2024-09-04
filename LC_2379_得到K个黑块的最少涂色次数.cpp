#include <iostream>
#include <string>
using namespace std;

// 给定一个字符串由W和B组成，分别表示白块和黑块，要获得k个连续的黑块，问最少的修改次数是多少

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = 0;
        int count = 0;
        int n = blocks.size();

        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'W')
                count++;
            if (i == k - 1) {
                res = count;
            }
            else if (i >= k) {
                if (blocks[i - k] == 'W')
                    count--;
                res = min(res, count);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string blocks("WBBWWBBWBW");
    int k = 7;
    cout << st.minimumRecolors(blocks, k) << endl;
    return 0;
}