#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        bool flag = false;
        int n = s.size();
        int count_A = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A')
                count_A++;
            if (s[i] == 'L' && i >= 2 && s[i - 1] == 'L' && s[i - 2] == 'L') {
                flag = true;
                break;
            }
        }
        if (!flag && count_A < 2)
            return true;
        return false;
    }
};

int main() {
    Solution st;
    string s("PPALLP");
    cout << boolalpha << st.checkRecord(s) << noboolalpha << endl;
    return 0;
}