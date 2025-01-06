//
// Created by 曹孟龙 on 25-1-6.
//

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

// 给定一个整数数组arr，和一个整数k，意思是整数数组arr可以串联k次，返回串联k次之后的子数组的值，结果对1e9+7取余

// 先对原始arr数组计算总和sum，根据sum和k分为几种情况：
// 如果sum<=0，k==1时，只对arr做一次dp即可；
// 如果sum>0,k==1时，也只做一次dp即可，所以可以和上边合起来 k==1；
// 如果sum<=0,k>=2时，那么只需要把两个arr拼接在一起做一次dp即可；
// 如果sum>0,k==2时，那么也只需要把两个arr拼接在一起做一次dp即可，这又可以和上边的合为一种情况；
// 如果sum>0,k>2时，那么需要先把两个arr拼接在一起做一次dp，然后加上中间k-2个sum的和即可。

// 所以总共分为三种情况：
// k==1；
// (sum<=0 && k>=2) || (sum>0 && k==2)
// sum>0 && k>2
// 第二第三种都需要把原始的两个arr拼接在一起做一次dp

class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;

    ll compute(vector<int> &arr) {
        int val = 0;
        int res = 0;
        for (int i: arr) {
            val = max(val, 0) + i;
            res = max(res, val);
        }
        return res;
    }

public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        if (k == 1) {
            return compute(arr) % MOD;
        } else {
            ll sum = accumulate(arr.begin(), arr.end(), 0);
            arr.insert(arr.end(), arr.begin(), arr.end());
            int ans = compute(arr);
            if (sum <= 0) {
                return ans;
            } else {
                return (1LL * ans + (k - 2) * sum) % MOD;
            }
        }
    }
};

int main() {
    Solution st;
    vector<int> arr{-5, -2, 0, 0, 3, 9, -2, -5, 4};
    int k = 5;
    cout << st.kConcatenationMaxSum(arr, k) << endl;
    return 0;
}
