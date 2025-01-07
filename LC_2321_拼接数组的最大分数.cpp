//
// Created by 曹孟龙 on 25-1-7.
//
#include <iostream>
#include <vector>
using namespace std;

// 有两个数组nums1和nums2，长度相同，可以交换一次或零次两个数组中的某个子数组，必须是对位子数组，然后返回sum(nums1)和sum(nums2)中的最大值
// 以用nums2中的某个子数组替换掉nums1中的对位子数组为例，那么sum(nums1) = sum(原始nums1) - (nums1[l]+...+nums1[r]) + nums2[l]+...+nums2[r]
// 重新排列后为sum(nums1) = sum(原始nums1) + (nums2[l]-nums1[l])+...+(nums2[r]-nums1[r])
// 要让sum(nums1)最大，那么就必须让(nums2[l]-nums1[l])+...+(nums2[r]-nums1[r])最大，就转化为了最基本的最大子数组和的问题

class Solution {
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        int sum_nums1 = 0;
        int sum_nums2 = 0;

        int val = 0;
        int max_val1 = 0, max_val2 = 0;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            sum_nums1 += nums1[i];
            sum_nums2 += nums2[i];

            val = max(val, 0) + nums2[i] - nums1[i];
            max_val1 = max(max_val1, val);
        }

        val = 0;
        for (int i = 0; i < n; i++) {
            val = max(val, 0) + nums1[i] - nums2[i];
            max_val2 = max(max_val2, val);
        }

        return max(sum_nums1, max(sum_nums2, max(sum_nums1 + max_val1,
                                                 sum_nums2 + max_val2)));
    }
};

int main() {
    Solution st;
    vector<int> nums1{10, 20, 50, 15, 30, 10}, nums2{40, 20, 10, 100, 10, 10};
    cout << st.maximumsSplicedArray(nums1, nums2) << endl;

    return 0;
}
