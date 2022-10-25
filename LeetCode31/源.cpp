#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//[1,3,2]  output:[3,1,2]  right:[2,1,3]
/*
    第一次想到的是注释掉的方法，但是对于[1,3,2]不行
    后来又采用了另一种方式
    首先倒序的找到一个数i，这个数比它后边的那个数小，
    然后再重头倒序的开始找到第一个比它大的数j，然后交换，交换后从i到最后进行升序排序
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       /* int lenght = nums.size();
        int i;
        for (i = lenght - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) break;
        }
        if(i>0) swap(nums[i], nums[i + 1]);
        sort(nums.begin() + i + 1, nums.end());*/

        int length = nums.size();
        int i, j;
        for (i = length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }

        if (i >= 0) {
            j = length - 1;
            while (j >= 0) {
                if (nums[j] > nums[i]) break;
                j--;
            }
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());

    }
};