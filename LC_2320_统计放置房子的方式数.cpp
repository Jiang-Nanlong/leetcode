#include <iostream>
#include <vector>
using namespace std;

// 路的两边各有n个位置，每个位置都可以建房子，但是房子不可以相邻，路两边的房子相互之间无影响。
// 问：最多有多少种建造房子的方式
// 其实只考虑道路一边就行，这又和LeetCode 198 打家劫舍一样了

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countHousePlacements(int n) {
        if (n == 1)
            return 4;
        vector<int> dp(n, 0);
        dp[0] = 2;
        dp[1] = 3;
        for (int i = 2; i < n; i++) {
            // 第i个位置考虑两种情况：
            // 如果第i个位置不建房子，那么第i-1个位置可建可不建，dp[i]=dp[i-1];
            // 如果第i个位置建房子，那么第i-1个位置不能建，第i-2个位置可建可不建，dp[i]=dp[i-2]
            // so,dp[i]=dp[i-1]+dp[i-2]
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return (long long)dp[n - 1] * dp[n - 1] % MOD;
    }
};

int main() {
    Solution st;
    int n = 4;
    cout << st.countHousePlacements(n) << endl;
    return 0;
}