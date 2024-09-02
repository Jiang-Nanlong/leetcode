#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i += k) {
            int j = i + k - 1;
            int sum = 0;
            while (j >= i) {
                sum += s[j--] - 'a';
            }
            res += (sum % 26 + 'a');
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("abcd");
    int k = 2;
    cout << st.stringHash(s, k) << endl;

    return 0;
}