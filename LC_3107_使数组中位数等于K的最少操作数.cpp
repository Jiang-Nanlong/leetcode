#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个整数数组nums和一个非负整数k，一次操作只能+1或-1，返回把数组的中位数变成k所需要的最少操作次数
// 如果数组长度为偶数，就选择中间两个数中较大值作为中位数
// 因为把偶数长度数组中间两个数中较大的数作为中位数，在递增排序中，那么我们就可以直接把右边那个数作为中位数，这样奇数长度和偶数长度计算中位数的位置就统一起来了,都是n/2,
// 然后第n/2个位置是中位数k，那么只需要让左边数小于等于k，右边的数大于等于k即可。
// 为了达到最少操作数，左边大于k的数都变成k，右边小于k的数也都变成k就行了。

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n / 2;
        long long count = (long long)abs(k - nums[mid]);

        for (int i = 0; i < mid; i++) {  // 左边大于k的数都变成k
            if (nums[i] > k)
                count += (long long)nums[i] - k;
        }
        for (int i = mid + 1; i < n; i++) {  // 右边小于k的数都变成k
            if (nums[i] < k)
                count += (long long)k - nums[i];
        }
        return count;
    }
};

int main() {
    Solution st;
    vector<int>nums{ 2,5,6,8,5 };
    int k = 7;
    cout << st.minOperationsToMakeMedianK(nums, k) << endl;
    return 0;
}