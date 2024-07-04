#include <iostream>
#include <vector>
using namespace std;

// 给定一个二进制数组nums，只有0和1，如果子数组中不存在相邻元素值相同的情况，就称这样的子数组为交替子数组，返回nums中交替子数组的数量。
// 因为这里要求的是子数组，也就是必须得是连续的。这样的话，如果一个子数组长度为3，那么说明三个数都是交替出现的，那么以第3个数字为结尾的子数组就共有3个，因为可以依次移除前边的元素。
// 所以计算子数组的数量，就变成了计算以nums中的每一个元素为结尾的子数组是交替子数组的最大长度，最后再把这些长度都加起来就是整个nums数组的交替子数组的数量。
// 开始以为是动态规划，后来发现不用设置dp数组就行，只需要计算以前一个元素为结尾的子数组的长度。如果当前元素和前一个相同，就重新开始计算子数组，如果不同就在前一个的长度上加1.

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 1;
        long long pre = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                pre = pre + 1;

            }
            else
                pre = 1;
            res += pre;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 0,1,1,1 };
    cout << st.countAlternatingSubarrays(nums) << endl;
    
    return 0;
}