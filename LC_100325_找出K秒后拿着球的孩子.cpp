#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        int x = k / (n - 1), y = k % (n - 1);
        if (x % 2 == 0)
            return y;
        else
            return n - 1 - y;
    }
};

int main() {
    Solution st;
    cout << st.numberOfChild(3, 5);
    return 0;
}