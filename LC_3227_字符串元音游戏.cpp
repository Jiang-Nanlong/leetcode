#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> uset{ 'a', 'e', 'i', 'o', 'u' };
        int count = 0;
        for (char c : s) {
            if (uset.find(c) != uset.end())
                count++;
        }
        if (count % 2 == 1 || (count > 0 && count % 2 == 0))
            return true;
        else
            return false;
    }
};

int main() {
    Solution st;
    string s("leetcoder");
    cout << boolalpha << st.doesAliceWin(s) << noboolalpha << endl;
    return 0;
}