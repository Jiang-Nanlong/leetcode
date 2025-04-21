//
// Created by cml on 25-4-21.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
                } else {
                    if (dp[i - 1] > 0) {
                        int index = i - dp[i - 1] - 1;
                        if (index >= 0 && s[index] == '(')
                            dp[i] =
                                    2 + dp[i - 1] + (index > 0 ? dp[index - 1] : 0);
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    int longestValidParentheses1(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(')
                stk.push(i);
            else {
                stk.pop();
                if (!stk.empty())
                    res = max(res, i - stk.top());
                else
                    stk.push(i);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s(")()())");
    cout << st.longestValidParentheses(s) << endl;
    cout << st.longestValidParentheses1(s) << endl;
    return 0;
}
