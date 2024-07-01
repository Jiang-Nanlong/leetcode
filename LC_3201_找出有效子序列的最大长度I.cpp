#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组，找出一个有效的子序列sub满足相邻元素之和对k取余后的结果都相同，这里的k是2
// 也就是(a+b)%k==(b+c)%k  ==>  a%k==c%k
// dp[i][j]表示以i为a%k和以j为b%k的最长子序列的长度，所以如果当前元素对k的余数为j，那么dp[i][j]=dp[j][i]+1.

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] % 2;
            for (int j = 0; j < 2; j++) {
                dp[j][x] = dp[x][j] + 1;
                res = max(res, dp[j][x]);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,3,4 };
    cout << st.maximumLength(nums) << endl;
    return 0;
}