//
// Created by ≤‹√œ¡˙ on 25-1-6.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals) {
        int val[26];
        for (int i = 0; i < 26; ++i) {
            val[i] = -1111;
        }

        for (int i = 0; i < chars.size(); i++) {
            int index = chars[i] - 'a';
            int value = vals[i];
            val[index] = value;
        }
        for (int i = 0; i < 26; i++) {
            if (val[i] == -1111)
                val[i] = i + 1;
        }

        int n = s.size();
        vector<int> dp(n, -1111);
        dp[0] = val[s[0] - 'a'];
        int res = max(0, dp[0]);

        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], 0) + val[s[i] - 'a'];
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main() {
    Solution st;
    string s("zox");
    string chars("zoxr");
    vector<int> vals{2, -5, -4, -5};
    int res = st.maximumCostSubstring(s, chars, vals);
    cout << res << endl;

    return 0;
}
