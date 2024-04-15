#include <iostream>
#include <vector>
using namespace std;

//给定一个整数，用平方数的和表示它，返回最小的平方数的个数
//除了平方的地方之外，其余的都和LeetCode 322 零钱兑换一样
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++)
                dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
        return dp[n];
    }

    //第二次做，先求出n以内的所有完全平方数作为物品，来填满背包。做完以后再看以前的代码，发现之前的更简单。
    int numSquares1(int n) {
        vector<int> num;
        for (int i = 1; i <= n; i++) {
            if (sqrt(i) == (int)sqrt(i)) {
                num.push_back(i);
            }
        }
        int count = num.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < count; i++) {
            for (int j = num[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - num[i]] + 1);
            }
        }
        return dp[n];
    }

    //还是这个方法更巧妙
    int numSquares2(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution st;
    cout << st.numSquares(12) << endl;
    cout << st.numSquares1(12) << endl;
    cout << st.numSquares2(12) << endl;
    return 0;
}