#include <iostream>
#include <vector>
using namespace std;

// 给定两个长度相同的数组nums和target，每次操作可以把nums中的子数组中的元素统一加一或减一，返回使得nums数组变为target数组的最少操作次数

// 这个题说是用了查分数组，但是我也没看出怎么回事。
// 做题的时候只看出了应该先计算两个数组各元素之间对应的差值，然后选择一段正负号相同的子数组统一修改。
// 如果当前元素的差的绝对值大于前一个元素的差的绝对值，那么说明在前一个元素对数组中的元素统一加一或减一时，当前位置无法满足，还需要abs(cur-pre)次操作，
// 如果当前元素的差的绝对值小于前一个元素的差的绝对值，那么说明前一个元素或前边元素中的某一个统一加一或减一时，当前位置已经满足条件了。

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long res = abs(target[0] - nums[0]);
        for (int i = 1; i < n; i++) {
            int pre = target[i - 1] - nums[i - 1];
            int cur = target[i] - nums[i];
            long long temp = 1LL * pre * cur;
            if (temp > 0) {
                if (abs(cur) < abs(pre))
                    continue;
                else
                    res += abs(cur - pre);
            }
            else {
                res += abs(cur);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3, 5, 1, 2 }, target{ 4, 6, 2, 4 };
    cout << st.minimumOperations(nums, target) << endl;
    return 0;
}