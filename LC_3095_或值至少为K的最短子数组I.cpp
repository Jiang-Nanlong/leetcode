#include <iostream>
#include <vector>
using namespace std;

// 给定一个非负整数数组nums，和一个整数k。如果一个数组中所有元素按位或的结果大于等于K，就说这个数组是特别的
// 返回nums中最短特别非空子数组的长度

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int cur = 0;
            for (int j = i; j < nums.size(); j++) {
                cur |= nums[j];
                if (cur >= k) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,3 };
    int k = 2;
    cout << st.minimumSubarrayLength(nums, k) << endl;
    return 0;
}