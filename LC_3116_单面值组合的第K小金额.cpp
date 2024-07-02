#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这个题相当于LeetCode 1201 丑数III的更一般化版本，丑数III中只有三个数字
// 这里应该还有一个背景知识，就是一个数m中有多少个可以由数n组成的数字？有m/n个。可以理解为把m等分，每一份都是n，共有m/n份，所以这些由n组成的数字可以是n,2n,3n...m/n*n
// 对于两个数呢？也就是一个数m中有多少个数，既可以由n1组成，也可以由n2组成？ 有m/lcm(n1,n2)个
// 所以对于多于1个的数组，求一个数m的范围内有多少个数可以被数组中的数整除就需要用到容斥原理

class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b) { // 计算最大公因数
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    ll lcm(ll a, ll b) { // 最小公倍数
        return a * b / gcd(a, b);
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto calc = [&](long long target) {   // 容斥原理计算一个数target中有多少个数可以被coins中的元素整除
            long long res = 0;
            for (int i = 1; i < (1 << n); i++) {  // 枚举coins的所有非空子集，二进制数i中的1代表哪些coins中的元素被选中
                int sign = -1;
                long long Least_Common_Multiple = 1;  // 最小公倍数
                for (int j = 0; j < n; j++) {  // 遍历coins中的每一个元素
                    if (i & (1 << j)) {   // 判断该元素是不是在子集i中的元素
                        Least_Common_Multiple = lcm(Least_Common_Multiple, coins[j]);   // 更新当前子集的最小公倍数
                        sign = -sign;  // 每一次都翻转符号，奇数为正，偶数位负
                    }
                }
                res += sign * (target / Least_Common_Multiple);  
            }
            return res;
        };

        sort(coins.begin(), coins.end());
        long long left = 1, right = 1LL * coins.back() * k;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (calc(mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    Solution st;
    vector<int> coins{ 3, 6, 9 };
    int k = 3;
    cout << st.findKthSmallest(coins, k) << endl;
    return 0;
}