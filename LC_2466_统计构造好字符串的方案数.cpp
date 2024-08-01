#include <iostream>
#include <vector>
using namespace std;

// low和high表示一个左闭右闭区间，zero表示每次可以在字符串末尾构造zero个0，one表示每次可以在字符串末尾构造one个1。
// 计算构造长度在low和high之间的字符串，有多少种构造方法，结果对1e9+7取余

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);  // dp[i]表示构造长度为i的字符串的方式数
        int mod = 1e9 + 7;
        dp[0] = 1;
        int res = 0;
        for (int i = 1; i <= high; i++) {
            if (i >= zero)  // 如果当前字符串长度大于等于zero，则可以在i-zero末尾加上zero个0构造得来
                dp[i] = dp[i - zero];
            if (i >= one)   // 如果当前字符串长度大于等于one，则可以在i-one末尾加上one个1构造得来
                dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= low)
                res = (res + dp[i]) % mod;
        }
        return res;
    }
};

int main() {
    Solution st;
    int low = 3, high = 3, zero = 1, one = 1;
    cout << st.countGoodStrings(low, high, zero, one) << endl;
    return 0;
}