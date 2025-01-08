//
// Created by ²ÜÃÏÁú on 25-1-8.
//

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string res;
        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                if (!res.empty() && num[i] - '0' < res[0] - '0') {
                    continue;
                }
                res = string(3, num[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    string num("6777133339");
    cout << st.largestGoodInteger(num) << endl;
    return 0;
}
