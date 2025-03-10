//
// Created by ²ÜÃÏÁú on 25-3-10.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int res = 0;
        for (int i = 0; i <= s.size() - k; i++) {
            int temp = stoi(s.substr(i, k));
            if (temp > 0 && num % temp == 0)
                ++res;
        }
        return res;
    }
};

int main() {
    Solution st;
    cout << st.divisorSubstrings(240, 2) << endl;
    return 0;
}
