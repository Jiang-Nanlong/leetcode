#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c >= '0' && c <= '9')
                stk.pop();
            else
                stk.push(c);
        }
        string res;
        while (!stk.empty()) {
            char c = stk.top();
            stk.pop();
            res += c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution st;
    string s("cb34");
    cout << st.clearDigits(s) << endl;
    return 0;
}