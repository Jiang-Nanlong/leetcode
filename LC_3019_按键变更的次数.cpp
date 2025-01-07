//
// Created by ²ÜÃÏÁú on 25-1-7.
//
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1])
                res++;
        }
        return res;
    }
};

int main() {
    Solution st;
    string s("aAbBcC");
    cout << st.countKeyChanges(s) << endl;
    return 0;
}
