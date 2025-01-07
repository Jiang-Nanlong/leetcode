//
// Created by 曹孟龙 on 25-1-7.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

// 给定一个环形数组nums，返回nums的非空子数组的最大和

// 这个题的难点主要是最大和的非空子数组可能会跨越边界。如果跨越边界的话直接求最大和不太好求，但是数组的总和一定，如果最大和的子数组跨越边界，那么中间连续这一段肯定是最小值。
// 那么求最大值的问题就变成了求中间子数组的最小值，但不保证子数组一定会跨边界，所以也求一遍原始子数组的最大值。
// 有一种特殊情况，如果中间最小值的子数组就是整个的nums，但是题目又要求nums的非空子数组的最大和，那么就返回原始子数组的最大值就行了


class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int val = 0;
        int maxval = INT_MIN;
        for (int i: nums) {
            val = max(val, 0) + i;
            maxval = max(val, maxval);
        }

        val = 0;
        int minval = INT_MAX;
        for (const int &i: nums) {
            val = min(val, 0) + i;
            minval = min(val, minval);
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == minval)
            return maxval;

        return max(maxval, sum - minval);
    }

    // 以上代码可以优化一下，仅用一个循环就行
    int maxSubarraySumCircular1(vector<int> &nums) {
        int max_val = 0;
        int min_val = 0;
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int sum = 0;

        for (const int &i: nums) {
            sum += i;
            max_val = max(max_val, 0) + i;
            max_sum = max(max_val, max_sum);

            min_val = min(min_val, 0) + i;
            min_sum = min(min_sum, min_val);
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};

int main() {
    Solution st;
    vector<int> nums{5, -3, 5};
    cout << st.maxSubarraySumCircular(nums) << endl;

    return 0;
}
