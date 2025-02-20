//
// Created by ≤‹√œ¡˙ on 25-2-20.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2, 0);
        int i = 0;
        while (n) {
            if (n & 1) {
                res[i % 2]++;
            }
            ++i;
            n >>= 1;
        }
        return res;
    }

    vector<int> evenOddBit1(int n) {
        vector<int> res(2, 0);

        for (int i = 0; n; n >>= 1) {
            res[i] += n & 1;
            i ^= 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> res = st.evenOddBit(50);
    cout << res[0] << " , " << res[1] << endl;

    vector<int> res1 = st.evenOddBit1(50);
    cout << res1[0] << " , " << res1[1] << endl;
    return 0;
}
