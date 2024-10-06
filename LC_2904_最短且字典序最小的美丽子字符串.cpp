#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res;
        int count = 0;
        int minlen = INT_MAX;
        for (int i = 0, j = 0; j < s.size(); j++) {
            count += s[j] == '1';
            while (count == k) {
                count -= s[i] == '1';
                string str = s.substr(i, j - i + 1);
                if ((minlen > j - i + 1) ||
                    (minlen == j - i + 1 && str < res)) {
                    minlen = j - i + 1;
                    res = str;
                }
                i++;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("1100100101011001001");
    int k = 7;
    cout << st.shortestBeautifulSubstring(s, k) << endl;
    return 0;
}