#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个整数数组nums，从nums中任选元素，让这些元素的乘积最大，返回这个最大乘积

class Solution {
public:
    // 这是我自己写的，先按绝对值排序，然后统计有多少个小于0的数，如果是偶数个就把数组中所有非0元素都乘起来；
    // 如果是奇数个，就把其余非0的数都乘起来，除了最大的那个负数
    long long maxStrength(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end(),
            [](const int& a, const int& b) { return abs(a) > abs(b); });
        int count = 0;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                count++;
                index = i;
            }
        }
        long long res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (count % 2 == 0) {
                if (res == INT_MIN)
                    res = nums[i];
                else if (nums[i] != 0)
                    res *= nums[i];
            }
            else {
                if (i == index)
                    continue;
                if (res == INT_MIN)
                    res = nums[i];
                else if (nums[i] != 0)
                    res *= nums[i];
            }
        }
        return res;
    }

    // 这是看的灵茶山艾府的答案
    // 对于数组中的每个元素都有两种情况：选 or 不选。
    // 在选的情况下，nums[i]本身可以作为一个最大值；如果nums[i]>0，那么nums[i]乘以前边元素乘积的最大值可以获得最大值；
    // 如果nums[i]<0，那么nums[i]乘以前边元素乘积的最小值可以获得最大值。
    // 所以这里我们只需要维护两个变量，即所选元素乘积的最大值和最小值即可。

    long long maxStrength1(vector<int>& nums) {
        long long mn = nums[0], mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            long long temp = mn;  // 后边会更新这个最小值，所以要先保存一下
            mn = min({ mn, x, mn * x, mx * x });  // 最小值可以从这四个选项中选出
            mx = max({ mx, x, temp * x, mx * x });  // 最大值可以从这四个选项中选出
        }
        return mx;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3,-1,-5,2,5,-9 };
    cout << st.maxStrength(nums) << endl;
    cout << st.maxStrength1(nums) << endl;
    return 0;
}