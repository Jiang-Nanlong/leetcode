#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int pos[26];
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'a'] = i;

        int res = 0;
        for (int i = 0; i < t.size(); i++)
            res += abs(i - pos[t[i] - 'a']);
        return res;
    }
};

int main() {
    Solution st;
    string s = "abc", t = "bac";
    cout << st.findPermutationDifference(s, t) << endl;
    return 0;
}
