#include <iostream>
#include <vector>
using namespace std;

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

    int nthUglyNumber(int n, int a, int b, int c) {
        ll left = min({ a, b, c }) - 1, right = 2000000001;
        ll lcm_ab = lcm(a, b);
        ll lcm_ac = lcm(a, c);
        ll lcm_bc = lcm(b, c);
        ll lcm_abc = lcm(lcm_ab, c);

        while (left < right) {
            ll mid = left + (right - left) / 2;
            ll count = mid / a + mid / b + mid / c - mid / lcm_ab -
                mid / lcm_ac - mid / lcm_bc + mid / lcm_abc;
            if (count < n)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    Solution st;
    cout << st.nthUglyNumber(3, 2, 3, 5) << endl;
    return 0;
}