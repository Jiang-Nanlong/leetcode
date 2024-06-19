#include <iostream>
using namespace std;

// 给定两个整数n和x，构造一个长度为n的正整数数组，数组递增，而且所有元素的按位与结果都是x
// 这个题思路其实很简单，数组的第一个数就是x，然后要想所有的数按位与结果都是x，就必须保持x中二进制1位不变，只改变0位。
// 如果把一个完整的数组中的每一个元素都按二进制展开，对比x中原本是0的那些位，这些位置组成的数分别是1,2,3...
// 所以第n个数，其实就是用n-1的二进制填充x的二进制中为0的位置

class Solution {
public:
    long long minEnd(int n, int x) {
        short num[64] = { 0 };
        n -= 1;
        for (int i = 0; x; x >>= 1, i++) {
            num[i] = x & 1;
        }

        int i = 0;
        while (n) {
            while (num[i] == 1)
                i++;
            num[i] = n & 1;
            i++;
            n >>= 1;
        }
        long long res = 0;
        for (int i = 63; i >= 0; i--) {
            res = res * 2 + num[i];
        }
        return res;
    }

    long long minEnd1(int n, int x) {
        long long res = x;
        n -= 1;
        int i = 0;
        while (n) {
            while (res >> i & 1)
                i++;
            res |= (long long)(n & 1) << i;
            i++;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    cout << st.minEnd1(6715154, 7193485) << endl;
    return 0;
}