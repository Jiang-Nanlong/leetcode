//
// Created by cml on 25-2-18.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    const int MOD = 1E9 + 7;

    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= pow(n, 1.0 / x) + 1; i++) {
            int temp = pow(i, x);
            for (int j = n; j >= temp; j--)
                dp[j] = (dp[j] + dp[j - temp]) % MOD;
        }

        return dp[n];
    }
};

int main() {
    Solution st;
    cout << st.numberOfWays(4, 1) << endl;
    return 0;
}
