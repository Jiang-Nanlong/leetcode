#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //自己写的，不对
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            else
                dp[i] = dp[i - 1];
        }
        return dp[n - 1];
    }

    //自己写的，不对，这个和答案已经很像了，用两个dp数组，一个维护[0,i]中递增子序列的个数，一个维护在最长长度时的子序列个数
    int findNumberOfLIS1(vector<int>& nums) {  // [3,1,2]有问题
        int n = nums.size();
        vector<int> dp(n, 1), len(n, 1);
        int maxlen = 1, index = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            else
                dp[i] = dp[i - 1];

            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    len[i] = max(len[i], len[j] + 1);
                }
            }
            if (len[i] >= maxlen) {
                maxlen = len[i];
                index = i;
            }
        }
        return dp[index];
    }

    //代码随想录的答案
    int findNumberOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), len(n, 1);  // dp[i]表示[0,i]上最长递增子序列的个数，len[i]表示[0,i]上最长递增子序列的长度
        int maxlen = 1;  // 记录最长的递增子序列的长度
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {  
                    if (len[j] + 1 > len[i]) {  // 如果[0,j]区间的最长自增子序列的长度+1大于当前[0,i]区间的最长递增子序列的长度，说明找到了一条更长的递增子序列
                        dp[i] = dp[j];          // 此时[0,i]上最长递增子序列的个数就和[0,j]上最长递增子序列的个数一样
                    }
                    else if (len[j] + 1 == len[i]) {  // 如果[0,j]上的最长递增子序列的长度+1和当前[0,i]上的最长递增子序列的长度一样，说明又找到了一条和[0,i]上最长递增子序列长度一样的子序列
                        dp[i] += dp[j];               // 所以[0,i]上最长递增子序列的个数就应该加上[0,j]上最长子序列的个数
                    }
                    len[i] = max(len[i], len[j] + 1);
                }
            }
            maxlen = max(maxlen, len[i]);  // 记录最长的自增子序列的长度
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == maxlen)
                res += dp[i];
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,5,4,7 };
    cout << st.findNumberOfLIS2(nums) << endl;
    return 0;
}