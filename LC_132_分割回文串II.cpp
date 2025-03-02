#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <climits>
using namespace std;

// 给定一个字符串，把字符串切割成一个或多个子串，每个子串都是一个回文串，求最少切割刀数

class Solution {
public:
    //这是我自己写的代码，不对。我开始想着先求出dp数组，然后再用类似于之前做过的走路的最小步数，也就是算覆盖的思路做。但是不行。
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        stack<int> stk;  //单调栈
        for (int i = 0; i < n; i++) {
            int cover = i;
            for (int j = i; j < n; j++) {
                if (dp[i][j]) {
                    cover = j;
                }
            }
            if (stk.empty() || cover > stk.top()) stk.push(cover);
            if (cover == n - 1) break;
        }
        return stk.size()-1;
    }

    //代码随想录的答案
    int minCut1(string s) {
        int n = s.size();
        vector<vector<bool>> ispalindrome(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {  //类似于LeetCode 5和LeetCode647这两题，先求出原来的dp数组，也就是看[i,j]是不是一个回文子串
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || ispalindrome[i + 1][j - 1]))
                    ispalindrome[i][j] = true;
            }
        }

        vector<int> dp(n, INT_MAX);//dp[i]表示把[0,i]的字符串切割成回文子串所需的最少刀数。这里还可以把dp[i]初始化成i，因为dp[i]切割成回文串最多也就是每个字母切一刀也就是i刀
        for (int i = 0; i < n; i++) {
            if (ispalindrome[0][i]) {  //如果[0,i]整个都是回文串，dp[i]就设为0
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (ispalindrome[j + 1][i])  //如果[j+1,i]为回文串，那么dp[i]=dp[j]+1,也就是从j的基础上再切一刀就可以
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }

    int minCut2(string s) {
        int n = s.size();
        vector<vector<bool>> isValid(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || isValid[i + 1][j - 1]))
                    isValid[i][j] = true;
            }
        }

        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            if (isValid[0][i]) {
                continue;
            }
            int res = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isValid[j + 1][i])
                    res = min(res, dp[j] + 1);
            }
            dp[i] = res;
        }
        return dp[n - 1];
    }
};

int main() {
    Solution st;
    string s("cabababcbc");
    cout << st.minCut1(s) << endl;
    return 0;
}