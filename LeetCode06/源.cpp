#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) return s;

        vector<string> res(numRows);
        int i = 0;
        int flag = -1;
        for (char& ch : s) {
            res[i] += ch;
            if (i == 0 || i == numRows - 1)
                flag = -flag;
            i += flag;
        }
        for (int j = 1; j < numRows; j++)
            res[0] += res[j];
        return res[0];
    }
    string s = "LEETCODE";
};
int main() {
    Solution* S = new Solution();
    cout << S->convert(S->s, 3) << endl;

}