#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组和一个整数k，如果某个连续子数组中出现了k个奇数数字，那么就认为这个子数组是一个优美子数组
// 返回优美子数组的数目

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int count1 = 0, count2 = 0;

        for (int i1 = 0, i2 = 0, j = 0; j < nums.size(); j++) {
            count1 += (nums[j] % 2);
            count2 += (nums[j] % 2);
            while (i1 <= j && count1 > k) { // while循环结束后，count1==k
                count1 -= (nums[i1++] % 2);
            }
           
            while (i2 <= j && count2 >= k) { // while循环结束后，count1==k-1
                count2 -= (nums[i2++] % 2);
            }
            res += i2 - i1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,1,2,1,1 };
    int k = 3;
    cout << st.numberOfSubarrays(nums, k) << endl;
    return 0;
}