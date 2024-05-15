#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int numR = 0, numL = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R')
                numR++;
            else
                numL++;
            if (numL == numR) {
                res++;
                numL = 0;
                numR = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("RLRRLLRLRL");
    cout << st.balancedStringSplit(s) << endl;
    return 0;
}