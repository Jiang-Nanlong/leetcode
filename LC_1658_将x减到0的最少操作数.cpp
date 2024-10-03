#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 给定一个整数数组nums和一个整数x，每一次操作中只能移除数组中最左边的元素和最右边的元素，x值也要减去相应的值，
// 如果x恰好减为0，则返回最小操作数，否则返回-1.

// 从数组的两端中凑出x，倒不如直接在数组中凑出accumulate(nums)-x，这样就不用考虑在数组两端删减了。

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int sum = 0;
        int maxlen = -1;  // 开始把maxlen=0了，如果最后maxlen=0就返回-1。这样不对，因为在结果成立的前提下，maxlen确实可能会等于0
        for (int i = 0, j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (i <= j && sum > target) { // 这里要注意i和j的位置，因为target可能是负数
                sum -= nums[i++];
            }
            if (sum == target)
                maxlen = max(maxlen, j - i + 1);
        }
        return maxlen == -1 ? -1 : nums.size() - maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309 };
    int x = 134365;
    cout << st.minOperations(nums, x) << endl;
    return 0;
}