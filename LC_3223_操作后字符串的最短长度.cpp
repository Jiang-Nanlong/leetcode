#include <iostream>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int num[26];
        memset(num, 0, sizeof(num));
        for (char c : s)
            num[c - 'a']++;

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (num[i] % 2 == 1)
                res += 1;
            else if (num[i] % 2 == 0 && num[i] > 0)
                res += 2;
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("abaacbcbb");
    cout << st.minimumLength(s) << endl;
    return 0;
}