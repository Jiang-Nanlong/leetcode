#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int maxlen = 1;
        bool flag = false;
        for (int i = 0, j = 1; j < s.size(); j++) {
            if (s[j] == s[j - 1]) {
                if (!flag)
                    flag = true;
                else {
                    while (s[i] != s[i + 1]) {
                        i++;
                    }
                    i++;
                }
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }

    int longestSemiRepetitiveSubstring1(string s) {
        int maxlen = 1;
        int same = 0;
        for (int i = 0, j = 1; j < s.size(); j++) {
            if (s[j] == s[j - 1])
                same++;
            while (same > 1) {
                if (s[i] == s[i + 1])
                    same--;
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }

};

int main() {
    Solution st;
    string s("52233");
    cout << st.longestSemiRepetitiveSubstring(s) << endl;
    cout << st.longestSemiRepetitiveSubstring1(s) << endl;
    return 0;
}