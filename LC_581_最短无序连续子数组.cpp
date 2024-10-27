#include <vector>
#include <iostream>
using namespace std;

// 给定一个整数数组，找出一个连续的子数组，如果把这个子数组按升序排序后，整个数组都是有序的了
// 返回子数组的长度

// 从左到右遍历，维护一个最大值，如果当前元素小于最大值的话，说明从前边某个位置开始到当前位置都是乱序的；
// 同理，从右向左遍历，维护一个最小值，如果当前元素大于最小值，说明从当前位置到后边的某个位置都是乱序的。
// 所以，来回遍历两次数组，就可以分别确定好子数组的左端和右端

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minnum = INT_MAX, maxnum = INT_MIN;
        int left = -1, right = -1;
        for (int i = 0; i < n; i++) {
            if (maxnum > nums[i])
                right = i;
            else
                maxnum = nums[i];

            if (minnum < nums[n - i - 1])
                left = n - i - 1;
            else
                minnum = nums[n - i - 1];
        }
        return left == -1 ? 0 : right - left + 1;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,6,4,8,10,9,15 };
    cout << st.findUnsortedSubarray(nums) << endl;
    return 0;
}