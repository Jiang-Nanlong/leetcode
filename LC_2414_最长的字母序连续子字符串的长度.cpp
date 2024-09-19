#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        if (s.size() == 1)
            return 1;
        int count = 1, res = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1] + 1) {
                count++;
                res = max(res, count);
            }
            else
                count = 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("abacaba");
    cout << st.longestContinuousSubstring(s) << endl;
    return 0;
}