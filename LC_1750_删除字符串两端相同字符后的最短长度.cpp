#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j && s[i] == s[j]) {
            while (i < j && s[i] == s[i + 1])
                i++;
            while (j > i && s[j] == s[j - 1])
                j--;
            i++;
            j--;
        }
        return i <= j ? j - i + 1 : 0;
    }
};
int main() {
    Solution st;
    string s("cabaabac");
    cout << st.minimumLength(s) << endl;
    return 0;
}