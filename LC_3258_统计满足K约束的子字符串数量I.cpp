#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count[2] = { 0, 0 };
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            count[s[j] - '0']++;
            while (count[0] > k && count[1] > k) {
                count[s[i++] - '0']--;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("10101");
    int k = 1;
    cout << st.countKConstraintSubstrings(s, k) << endl;
    return 0;
}