#include <iostream>
#include <vector>
using namespace std;

// 给定一个正整数数组和一个整数k，返回数组中所有元素乘积严格小于k的子数组的个数

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)  // 因为数组的最小元素就是1，乘积肯定大于等于1，而有要求乘积必须严格小于k，如果k是1的话也是没有满足要求的数组的
            return 0;
        int product = 1;
        int res = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (product >= k) {
                product /= nums[i++];
            }
            res += j - i + 1;  // 统计以j为右端点的所有子数组的个数
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 10,5,2,6 };
    int k = 100;
    cout << st.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}