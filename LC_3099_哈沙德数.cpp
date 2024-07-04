#include <iostream>
using namespace std;

// 如果一个数能被它的各位之和整除，就返回各位之和，否则返回-1

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int y = x;
        int num = 0;
        while (y) {
            num += y % 10;
            y /= 10;
        }
        if (x % num == 0) return num;
        return -1;
    }
};

int main() {
    Solution st;
    cout << st.sumOfTheDigitsOfHarshadNumber(18) << endl;
    return 0;
}