#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int res = 0;
        int n = 1;
        while (num1 && num2 && num3) {
            int a = num1 % 10, b = num2 % 10, c = num3 % 10;
            res += min(a, min(b, c)) * n;
            n *= 10;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return res;
    }

    int generateKey1(int num1, int num2, int num3) {
        int res = 0;
        int i = 0;
        while (num1 && num2 && num3) {
            int num = min({num1 % 10, num2 % 10, num3 % 10});
            res = res + num * pow(10, i++);
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return res;
    }
};

int main() {
    Solution st;
    int num1 = 987, num2 = 879, num3 = 798;
    cout << st.generateKey(num1, num2, num3) << endl;
    return 0;
}