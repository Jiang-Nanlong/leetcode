#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 这是我一开始的写法，用动态规划，能解决部分用例，但是遇到[2,15,14,18]这样的就不行了
    int maxTotalReward(vector<int> &rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<int> dp(rewardValues.begin(), rewardValues.end());
        int maxres = rewardValues[0];
        for (int i = 1; i < rewardValues.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] < rewardValues[i] && rewardValues[j] < rewardValues[i]) {
                    dp[i] = max(dp[i], max(rewardValues[i] + dp[j], rewardValues[i] + rewardValues[j]));
                } else if (dp[j] >= rewardValues[i] && rewardValues[j] < rewardValues[i])
                    dp[i] = max(dp[i], rewardValues[i] + rewardValues[j]);
                maxres = max(maxres, dp[i]);
            }
        }
        for (int i: dp)
            cout << i << " ";
        return maxres;
    }

    // 后来看过别人写的题解后发现是个背包问题，因为题目要求的是当rewardValues[i]大于当前总奖励x时，才将rewardValues[i]加在x上。
    // 这就正好契合背包中的物品重量必须小于背包容量
    int maxTotalReward1(vector<int> &rewardValues) {
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

    // 时隔半年以后又一次坐到这个题。背包问题无非就是选不选择当前元素的问题，
    // 在这个问题中，如果要选择当前元素有个条件，就是当前元素的值要大于背包的价值，所以给这个题加了限制。
    // 而且如果数组中有多个相同的值，那么只会使用其中一个，因为使用一个值的条件是该值大于总奖励，
    // 如果该值已经加在了总奖励里，那么下一次遇到这个值肯定就不会大于总奖励了

    // 这里有点想不明白为什么背包价值不会超过背包容量
    // 这个地方好像跟之前的背包问题并没区别，但之前没考虑过这个问题，还是得重新看一下背包
    int maxTotalReward2(vector<int> &rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        int temp = rewardValues.back();
        vector<int> dp(temp, 0);
        for (int i = 0; i < rewardValues.size(); i++) {
            for (int j = temp - 1; j >= rewardValues[i]; j--) {
                int x = rewardValues[i] > dp[j - rewardValues[i]] ? dp[j - rewardValues[i]] : dp[rewardValues[i] - 1];
                dp[j] = max(dp[j], x + rewardValues[i]);
            }
        }
        return dp[temp - 1] + temp;
    }
};

int main() {
    Solution st;
    vector<int> rewardValues{1, 1, 3, 3};
    cout << st.maxTotalReward1(rewardValues) << endl;
    return 0;
}
