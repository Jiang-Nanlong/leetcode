#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 给定一个数组，数组是一个可以无限延伸的数组，也就是无限长的数组的一个单位是nums，数组由无穷个nums数组依次组成
// 在数组中找出最短的子数组，子数组的和等于target

// 想到用滑动窗口很简单，主要是不知道应该把快指针的上限设为多少。
// 可以画图表示，target所在的那个子数组一定是由m个完整的nums数组和两段不完整的子数组拼接组成，
// 我们可以不考虑完整的m个nums数组，只考虑那两个不完整的，其实也就是target对nums数组的和取余后的结果
// 这样用一定可以用两个nums数组表示，最后再加上m个完整nums数组的长度就可以求的结果了

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int m = target / total;
        target = target % total;
        long long sum = 0;
        int minlen = INT_MAX;

        for (int i = 0, j = 0; j < 2 * n; j++) {
            sum += nums[j % n];
            while (sum > target) {
                sum -= nums[(i++) % n];
            }
            if (sum == target) {
                minlen = min(minlen, j - i + 1);
            }
        }
        return minlen == INT_MAX ? -1 : minlen + m * n;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,2,2,1,2,1,2,1,2,1 };
    int target = 83;
    cout << st.minSizeSubarray(nums, target) << endl;
    return 0;
}