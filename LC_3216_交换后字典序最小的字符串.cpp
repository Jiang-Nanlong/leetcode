#include <iostream>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        string res = s;
        for (int i = 1; i < s.size(); i++) {
            string temp = s;
            if (((s[i] - 'a') % 2 ^ (s[i - 1] - 'a') % 2) == 0) {
                swap(temp[i], temp[i - 1]);
                if (res > temp)
                    res = temp;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("45320");
    cout << st.getSmallestString(s) << endl;
    return 0;
}