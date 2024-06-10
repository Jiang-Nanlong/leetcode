#include <iostream>
#include <vector>
using namespace std;

// 看着答案上都在说前缀和，看见好几次了，学一下

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long> dp(n, 1);
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = (long long)(dp[j] + dp[j - 1]) % (1000000007);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution st;
    cout << st.valueAfterKSeconds(4, 5) << endl;
    return 0;
}