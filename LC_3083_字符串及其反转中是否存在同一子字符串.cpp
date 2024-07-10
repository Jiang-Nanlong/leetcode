#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        string reverse_s(s);
        reverse(reverse_s.begin(), reverse_s.end());
        for (int i = 0; i < s.size() - 1; i++) {
            if (reverse_s.find(s.substr(i, 2)) != -1)
                return true;
        }
        return false;
    }
};

int main() {
    Solution st;
    string s("abcba");
    cout << boolalpha << st.isSubstringPresent(s) << noboolalpha << endl;
    return 0;
}