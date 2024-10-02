#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个数组和一个非负整数k，你可以把数组中的每一个元素i修改为[i-k, i+k]之间的任意数。
// 数组美丽值的定义为数组中由相同元素组成的最长子序列的长度。

// 这是一个滑动窗口题，因为数组中元素的顺序对结果没有影响，可以先排序。
// 既然是窗口题，那么什么时候可以增大窗口，什么时候可以缩小窗口呢？
// 数组中的每一个元素nums[i]都维持一个[nums[i]-k,nums[i]+k]的区间，要把一段窗口内的值都变为同一个，这些值的区间应该有交集，
// 贪心的想只要窗口最左边元素的区间和窗口最右边元素的区间有交集即可。

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            while (nums[j] - k > nums[i] + k) {
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 4,6,1,2 };
    int k = 2;
    cout << st.maximumBeauty(nums, k) << endl;
    return 0;
}