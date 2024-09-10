#include <iostream>
#include <vector>
using namespace std;

// 给定一个长度为n的数组，你需要从下标0开始，到下标n-1，每次从下标i到下标j的得分为(j-i)*nums[i]
// 返回到达最后一个下标处的最大总得分

// 可以把j-i当成长方形的长，nums[i]当成长方形的宽，求面积的最大值
// 也可以把(j-i)*nums[i]拆开，nums[i]+nums[i]+nums[i]+...+nums[i]，所以nums[i]在遇到小的时候就保持原值，如果遇到更大的就变成更大的

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] >= nums[i]) {
                res += 1LL * (j - i) * nums[i];
                i = j;
            }
            j++;
        }
        if (nums.back() < nums[i])
            res += 1LL * (j - i - 1) * nums[i];
        return res;
    }

    // 灵茶山艾府的代码，太简洁了
    long long findMaximumScore1(vector<int>& nums) {
        long long res = 0;
        int temp = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            temp = max(temp, nums[i]);
            res += temp;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 4,3,1,3,2 };
    cout << st.findMaximumScore(nums) << endl;
    cout << st.findMaximumScore1(nums) << endl;
    return 0;
}