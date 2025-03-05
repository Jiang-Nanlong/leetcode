//
// Created by ²ÜÃÏÁú on 25-3-5.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1)
            return "";
        int i = 0;
        while (i < n / 2) {
            if (palindrome[i] == 'a')
                i++;
            else
                break;
        }
        if (i == n / 2)
            palindrome[n - 1] = 'b';
        else
            palindrome[i] = 'a';

        return palindrome;
    }
};

int main() {
    Solution st;
    cout << st.breakPalindrome("abccba");
    return 0;
}
