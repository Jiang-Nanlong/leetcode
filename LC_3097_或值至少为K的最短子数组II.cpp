#include <iostream>
#include <vector>
using namespace std;

// 和LeetCode 3095 或值至少 K 的最短子数组I 一样的要求，不过就是数据量更大。
// 这是一个滑动窗口题，感觉这个题的思路太巧妙了。
// 计算子数组的按位或结果，同时用一个数组bit来计算数组每个元素每个bit位为1的次数，以便在缩小窗口时用。
// nums[i]<=1e9，换算成二进制也就是2^30，所以bit数组共30个元素。
// 一旦子数组的按位或结果大于等于k了，就开始缩小窗口。减去每个元素的每个bit位在数组中的1的个数，如果为0了，说明在窗口的左边界，该bit位已经没有1了，
// 就可以把前边按位或的结果在该bit位变为0了。
// 这种思路有一个背景就是按位或的结果总是递增的，只要数组中的某个位置之前，有一个元素在该bit位为1，整个数组在该位置的按位或结果就为1

class Solution {
public:
    void add_bit(vector<int>& bit, int num) {
        for (int i = 1, j = 0; i <= num; i <<= 1, j++)
            if (num & i)
                bit[j]++;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bit(30, 0);
        int res = INT_MAX;
        int sum = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum |= nums[i];
            add_bit(bit, nums[i]);
            while (j <= i && sum >= k) {
                res = min(res, i - j + 1);
                for (int t = 1, id = 0; t <= nums[j]; t <<= 1, id++) {
                    if (t & nums[j]) {
                        bit[id]--;
                        if (bit[id] == 0)
                            sum ^= t;
                    }
                }
                j++;
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