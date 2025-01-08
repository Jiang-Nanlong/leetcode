//
// Created by 曹孟龙 on 25-1-8.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//  给定一个整数数组，返回乘积最大的子数组的值

// 乘积的子数组和加法的整数组最大的区别就是乘积会根据当前值的正负出现不一样的结果，所以不仅要维护以前一个字符为结尾的子数组的最大乘积，也要维护以前一个字符为结尾的子数组的最小乘积
// 当前值和前边子数组的乘积的最大值可能出现在这两种情况下，还一种就是当前字符本身就是最大值

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp_max(n), dp_min(n);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = dp_max[i - 1];
            dp_max[i] = max(
                {dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i]});
            dp_min[i] = min({temp * nums[i], dp_min[i - 1] * nums[i], nums[i]});
            res = max(res, dp_max[i]);
        }

        return res;
    }

    int maxProduct1(vector<int> &nums) {
        int res = INT_MIN;
        int max_val = 1;
        int min_val = 1;

        for (int i: nums) {
            int temp = max_val;
            max_val = max({max_val * i, min_val * i, i});
            min_val = min({min_val * i, temp * i, i});

            res = max(res, max_val);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{2, 3, -2, 4};
    cout << st.maxProduct(nums) << endl;
    cout << st.maxProduct1(nums) << endl;

    return 0;
}
