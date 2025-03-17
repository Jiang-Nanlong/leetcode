//
// Created by 曹孟龙 on 25-3-17.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 要求用时间复杂度O(n)的方法计算出数组中最长的递增子序列，递增必须是连续递增。
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;
        unordered_set<int> uset(nums.begin(), nums.end());
        for (int i: uset) {
            // 如果i-1存在，那么就不用统计以i开始的子序列的长度了，因为以i-1开始的子序列会统计上
            if (uset.find(i - 1) != uset.end())
                continue;

            int j = i + 1;
            while (uset.find(j) != uset.end())
                j++;

            res = max(res, j - i);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{1, 0, 1, 2};
    cout << st.longestConsecutive(nums) << endl;
    return 0;
}
