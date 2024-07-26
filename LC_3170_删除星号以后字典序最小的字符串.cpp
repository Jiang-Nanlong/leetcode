#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        string res;
        for (char c : s) {
            if (c != '*') {
                res.push_back(c);
            }
            else {
                if (!res.empty()) {
                    char minChar = res[0];
                    int minIndex = 0;
                    for (int i = 1; i < res.size(); i++) {
                        if (res[i] <= minChar) {
                            minChar = res[i];
                            minIndex = i;
                        }
                    }
                    res.erase(res.begin() + minIndex);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("aaba*");
    string res = st.clearStars(s);
    cout << res << endl;
    return 0;
}