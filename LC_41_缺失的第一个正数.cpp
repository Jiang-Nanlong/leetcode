//
// Created by 曹孟龙 on 25-3-31.
//
#include <iostream>
#include <vector>
using namespace std;

// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数
// 要求时间复杂度为O(n)，常数级别空间的解决方案

// 求出数组的长度，把每个在数组长度范围内的正整数找到它对应应该在的位置，比如1保存在第0个位置，2保存在第1个位置

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            // 这里要用while循环，因为如果用if的话，新交换过来的数字还没有在正确的位置，而这时候i又增加了，就会跳过当前新交换过来的数字
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};

int main() {
    Solution st;
    vector<int> nums{3, 4, -1, 1};
    cout << st.firstMissingPositive(nums) << endl;
    return 0;
}
