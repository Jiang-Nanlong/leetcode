#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1", res;
        if (n == 1) return s;
        for (int k = 1; k < n; k++) {
            for (int i = 0, j = 0; i < s.size(); ) {
                while (s[i] == s[j]) j++;
                res += j - i + '0';
                res += s[i];
                i = j;
            }
            s = res;
            res.clear();
        }
        return s;
    }
};

int main() {
    Solution* s = new Solution();
    cout << s->countAndSay(4) << endl;
}