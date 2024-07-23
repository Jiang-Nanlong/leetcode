#include <iostream>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        if (n < k)
            return -1;
        int res = 0;
        while (n || k) {
            int bitn = n & 1;
            int bitk = k & 1;
            if (bitk == 1 && bitn == 0)
                return -1;
            else if (bitk == 0 && bitn == 1)
                res++;
            n >>= 1;
            k >>= 1;
        }
        while (n) {
            if (n & 1)
                res++;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    int n = 13, k = 4;
    cout << st.minChanges(n, k) << endl;
    return 0;
}