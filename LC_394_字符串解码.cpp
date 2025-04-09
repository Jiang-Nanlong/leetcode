//
// Created by cml on 25-4-9.
//
#include <iostream>
#include <functional>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        function<string()> dfs = [&]() -> string {
            if (i == s.size() || s[i] == ']')
                return "";

            string res;
            if (std::isdigit(s[i])) {
                int cnt = 0;
                while (i < s.size() && std::isdigit(s[i]))
                    cnt = cnt * 10 + s[i++] - '0';
                ++i;
                string temp = dfs();
                ++i;
                while (cnt--)
                    res += temp;
            } else if (std::isalpha(s[i])) {
                res += s[i++];
            }
            return res + dfs();
        };
        return dfs();
    }
};

int main() {
    Solution s;
    cout << s.decodeString("3[a2[c]]") << endl;
    return 0;
}
