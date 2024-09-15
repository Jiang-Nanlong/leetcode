#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int count = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (s[j] != '*') {
                s[i] = s[j];
                i++;
            }
            else {
                i--;
                count++;
            }
        }
        return s.substr(0, s.size() - 2 * count);
    }
};

int main() {
    Solution st;
    string s("leet**cod*e");
    cout << st.removeStars(s) << endl;
    return 0;
}