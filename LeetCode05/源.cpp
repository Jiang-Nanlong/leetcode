#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int length = s.length();
        int maxlength = 0;
        int i = 0, j = 0, k = 0;
        int len = 0;
        for (i = 0; i < 2 * length - 1; i++) {
            if (i % 2 == 0) {     //×Ö·ûÎ»
                for (j = 0; i/2 + j < length && i/2 - j >= 0; j++) {
                    if (s[i/2 + j] == s[i/2 - j]) {
                        len = 2 * j + 1;
                    }
                    else {
                        break;
                    }
                }
                if (maxlength < len) {
                    maxlength = len;
                    start = i / 2 - (j-1) ;
                    end = i / 2 + (j-1);
                }
            }
            if (i % 2 == 1) {     //¿Õ¸ñÎ»
                for (k = 0; (i + 2 * k + 1) / 2 < length && (i - 2 * k - 1) / 2 >= 0; k++) {
                    if (s[(i + 2 * k + 1) / 2] == s[(i - 2 * k - 1) / 2]) {
                        len = 2 * (k+1);
                    }
                    else {
                        break;
                    }
                }
                if (maxlength < len) {
                    maxlength = len;
                    start = (i - 2 * (k - 1) - 1) / 2;
                    end = (i + 2 * (k - 1) + 1) / 2;
                }
            }
        }
        return s.substr(start, maxlength);
    }

    string str = "xbabab";
};
int main() {
    Solution *s = new Solution();
    cout << s->longestPalindrome(s->str) << endl;
}