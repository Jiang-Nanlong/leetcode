#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;

        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor >0))
            sign = -1;

        //转换成负数进行计算，负数的范围更大
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;

        return sign * calculate(dividend, divisor);
    }

private:
    int calculate(int dividend, int divisor) {
        if (dividend >= divisor) return dividend > divisor ? 0 : 1;

        int count = 1;
        int res = 0;
        int divisor_1 = divisor;

        while (dividend <= divisor_1 && divisor_1 < 0) {
            dividend -= divisor_1;
            divisor_1 += divisor_1;
            res += count;
            count += count;
        }
        return res + calculate(dividend, divisor);
    }
};

int main() {
    Solution* s = new Solution();
    cout << s->divide(2147483647, 1) << endl;

}