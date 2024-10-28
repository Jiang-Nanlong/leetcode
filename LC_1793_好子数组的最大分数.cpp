#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组，和一个整数k。一个子数组的分数定义为子数组中元素的最小值乘以子数组中元素的个数
// 一个子数组的两端下标要满足i<=k<=j，返回子数组的最大分数

// 可以把元素的值理解为高度，子数组的分数就是面积

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k], min_h = nums[k];
        int n = nums.size();
        int i = k, j = k;
        for (int t = 0; t < n - 1; t++) {
            if (j == n - 1 && i > 0)
                min_h = min(min_h, nums[--i]);
            else if (i == 0 && j < n - 1)
                min_h = min(min_h, nums[++j]);
            else if (nums[i - 1] > nums[j + 1])  // 谁大就往哪个方向移动，因为往低的方向移动对面积的负作用更大
                min_h = min(min_h, nums[--i]);
            else
                min_h = min(min_h, nums[++j]);
            res = max(res, min_h * (j - i + 1));
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,4,3,7,4,5 };
    int k = 3;
    cout << st.maximumScore(nums, k) << endl;
    return 0;
}