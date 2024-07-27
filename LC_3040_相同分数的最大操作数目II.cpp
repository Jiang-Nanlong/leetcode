#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// 和LeetCode 3038差不多，但是3038只能删除前边两个字符。这里可以删除前边两个，后边两个，最前最后两个，还是要求每次删除的时候两个字符加一起的分数一样，返回最大的操作次数。

// 这个题就是递归+记忆化搜索

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));   // 记录[i,j]区间内的操作次数，初始值都为-1

        function<int(int, int, int)> dfs = [&](int i, int j, int score) {
            if (j - i < 1)  // 如果区间内的字符少于一个
                return 0;

            if (dp[i][j] != -1)  // 如果该区间上的操作次数不是-1，说明已经计算过了，记忆化搜索，直接使用就行了
                return dp[i][j];

            // 下边开始计算区间[i,j]上的操作次数
            int res = 0;
            if (nums[i] + nums[i + 1] == score)  // 如果区间前两个字符的和与分数相同，则删除前两个字符
                res = max(res, 1 + dfs(i + 2, j, score));
            if (nums[i] + nums[j] == score)      // 如果区间两端字符的和与分数相同，则删除两端字符
                res = max(res, 1 + dfs(i + 1, j - 1, score));
            if (nums[j - 1] + nums[j] == score)  // 如果区间后两个字符的和与分数相同，则删除后两个字符
                res = max(res, 1 + dfs(i, j - 2, score));

            dp[i][j] = res;  // 最后更新dp[i][j]的值
            return res;
        };

        int a = dfs(2, n - 1, nums[0] + nums[1]);
        int b = dfs(1, n - 2, nums[0] + nums[n - 1]);
        int c = dfs(0, n - 3, nums[n - 2] + nums[n - 1]);
        return max({ a, c, b }) + 1;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3,2,1,2,3,4 };
    cout << st.maxOperations(nums) << endl;
    return 0;
}