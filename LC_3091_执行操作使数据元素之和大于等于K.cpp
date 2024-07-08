#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(int k) {
        if (k == 1)
            return 0;
        int res = INT_MAX;
        for (int i = 1; i <= k; i++) {  // 把k平均分为i份
            int count = k / i;
            if (k % i != 0)  // 如果k/i有余数，就把结果加一，类似于向上取整
                count++;
            res = min(res, count - 1 + i - 1);  // 第一个数变为k/i向上取整需要count-1步，这个数再变成i个相同的，需要i-1步
        }
        return res;
    }
};

int main() {
    Solution st;
    cout << st.minOperations(11) << endl;
    return 0;
}