#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int res = 0;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == '1') {
                count++;
                i++;
            }
            else {
                res += count;
                while (++i < n && s[i] == '0')
                    ;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("1001101");
    cout << st.maxOperations(s) << endl;
    return 0;
}