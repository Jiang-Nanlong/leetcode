#include <iostream>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == c)
                count++;
        long long res = 0;
        for (int i = 1; i <= count; i++)
            res += i;
        return res;
    }
};

int main() {
    Solution st;
    string s("abada");
    char c = 'a';
    cout << st.countSubstrings(s, c) << endl;
    return 0;
}