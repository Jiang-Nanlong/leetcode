#include <iostream>
#include <vector>
#include <string>
using namespace std;

//������LeetCode 647��ֱһģһ����������û��������

class Solution {
public:
    // ��̬�滮��dp[i][j]��ʾs[i]��s[j]������ұ������ǲ��ǻ����Ӵ�
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxlen = 1, left = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }
                if (dp[i][j] && j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    left = i;
                }
            }
        }
        return s.substr(left, maxlen);
    }

    //˫ָ������
    int maxlen = 0;
    int left = 0;
    string longestPalindrome1(string s) {
        for (int i = 0; i < s.size(); i++) {
            ispalindromic(s, i, i + 1);
            ispalindromic(s, i, i);
        }
        return s.substr(left, maxlen);
    }

    void ispalindromic(string& s, int begin, int end) {
        while (begin >= 0 && end < s.size() && s[begin] == s[end]) {
            begin--;
            end++;
        }

        if (end - begin - 1 > maxlen) {
            left = begin + 1;
            maxlen = end - begin - 1;
        }
    }
};

int main() {
    Solution st;
    string s("babad");
    cout << st.longestPalindrome(s) << endl;
    cout << st.longestPalindrome1(s) << endl;
    return 0;
}