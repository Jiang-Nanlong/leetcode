#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlen = 0;
        int cost = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            cost += abs(s[j] - t[j]);
            while (cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    string s("abcd"), t("bcdf");
    int maxCost = 3;
    cout << st.equalSubstring(s, t, maxCost) << endl;
    return 0;
}