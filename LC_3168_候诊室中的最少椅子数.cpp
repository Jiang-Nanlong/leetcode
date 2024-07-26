#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int count = 0, maxcount = 0;
        for (char c : s) {
            if (c == 'E') {
                count++;
                if (count > maxcount) maxcount = count;
            }
            else {
                count--;
            }
        }
        return maxcount;
    }
};

int main() {
    Solution st;
    string s("ELELEEL");
    int res = st.minimumChairs(s);
    cout << res << endl;
    return 0;
}