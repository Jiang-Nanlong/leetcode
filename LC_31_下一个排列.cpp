#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// 开始我只想到了要nums[j]>nums[i]时进行互换，但没想到后边的还要重新排序
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {  // 这两个循环也有说法，开始的时候我是把i从后向前遍历，j初始化为i-1，j也向前遍历。
            for (int j = nums.size() - 1; j > i; j--) {  // 但是在遇到4, 2, 0, 2, 3, 2, 0这个序列时就出错了。后来想想确实不对，当前元素nums[i]应该和位权更小的互换，而不是位权更大的，也就是应该和序号更大的进行互换
                if (nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        // 运行到这里说明整个数组是从大到小排列的，直接逆序就行了
        reverse(nums.begin(), nums.end());
    }
};


int main() {
    Solution st;
    vector<int> nums{ 4, 2, 0, 2, 3, 2, 0 };
    st.nextPermutation(nums);
    for (int i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}