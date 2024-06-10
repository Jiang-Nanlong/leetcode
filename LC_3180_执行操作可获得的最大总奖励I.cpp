#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 这是我一开始的写法，用动态规划，能解决部分用例，但是遇到[2,15,14,18]这样的就不行了
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<int> dp(rewardValues.begin(), rewardValues.end());
        int maxres = rewardValues[0];
        for (int i = 1; i < rewardValues.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] < rewardValues[i] && rewardValues[j] < rewardValues[i]) {
                    dp[i] = max(dp[i], max(rewardValues[i] + dp[j], rewardValues[i] + rewardValues[j]));
                }
                else if (dp[j] >= rewardValues[i] && rewardValues[j] < rewardValues[i])
                    dp[i] = max(dp[i], rewardValues[i] + rewardValues[j]);
                maxres = max(maxres, dp[i]);
            }
        }
        for (int i : dp)
            cout << i << " ";
        return maxres;
    }

    // 后来看过别人写的题解后发现是个背包问题，因为题目要求的是当rewardValues[i]大于当前总奖励x时，才将rewardValues[i]加在x上。
    // 这就正好契合背包中的物品重量必须小于背包容量
    int maxTotalReward1(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int bagsize = rewardValues.back();
        vector<int> dp(bagsize, 0);
        for (int i = 0; i < rewardValues.size(); i++) {
            for (int j = bagsize - 1; j >= rewardValues[i]; j--) {
                // 计算x的过程是最关键的。
                // 如果当前元素的值大于去掉当前元素值以后的背包所装的重量，就按正常的计算方法；
                // 如果当前元素的值小于等于去掉当前元素值以后的背包所装的重量，为了加上当前元素，那么x只能是表示容量小于当前背包容量的背包所装的最大值，那么x最大就只能等于dp[rewardValues[i] - 1]
                int x = rewardValues[i] > dp[j - rewardValues[i]] ? dp[j - rewardValues[i]] : dp[rewardValues[i] - 1];
                dp[j] = max(dp[j], x + rewardValues[i]);
            }
        }
        return dp[bagsize - 1] + bagsize;
    }
};

int main() {
    Solution st;
    vector<int> rewardValues { 1, 1, 3, 3 };
    cout << st.maxTotalReward1(rewardValues) << endl;
    return 0;
}