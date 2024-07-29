#include <iostream>
#include <vector>
using namespace std;

// 给定一个区间[l,r]，判断区间内有多少数字不是特殊数字。
// 特殊数字是指除了它本身外，之后两个真因数。
// 每个数都有一个因数1，那么除了1还有一个因数。

class Solution {
public:

    // 其实可以写个程序看看特殊数字都是那些数，这些数只有两个真因数，一个是1，另一个是一个质数
    // 每一个特殊数字其实就是它的质数真因数的平方
    void getnum() {
        for (int i = 1; i < 500; i++) {
            int count = 0;
            for (int j = 1; j < i; j++) {
                if (i % j == 0)
                    count++;
            }
            if (count == 2)
                cout << i << endl;
        }
    }

    int nonSpecialCount(int l, int r) {
        vector<int> prime = getPrime(sqrt(r));
        int res = 0;
        for (int i : prime) {
            int ii = i * i;
            if (ii >= l && ii <= r)
                res++;
        }
        return r - l + 1 - res;
    }

    // 埃拉托斯尼特筛法求质数，
    // 要求得n以内的所有质数，必须把不大于根号n的所有质数的倍数都剔除，剩下的都是质数。
    vector<int> getPrime(int r) {
        vector<bool> isprime(r + 1, true);
        isprime[0] = false;
        isprime[1] = false;
        for (int i = 2; i * i <= r; i++)  // 这里只需要算到根号n即可
            if (isprime[i]) {
                for (int j = i * i; j <= r; j += i)
                    isprime[j] = false;
            }
        vector<int> res;
        for (int i = 2; i <= r; i++)
            if (isprime[i])
                res.push_back(i);
        return res;
    }

    
};

int main() {
    Solution st;
    st.getnum();
    cout << st.nonSpecialCount(4, 16) << endl;
    return 0; 
}