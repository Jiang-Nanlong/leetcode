#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// power数组每个元素表示一个咒语的伤害值，可能有多个咒语有相同的伤害值。如果使用了伤害值为power[i]的咒语时，他们就不能使用伤害值为power[i]-2,power[i]-1,power[i]+1,power[i]+2的咒语
// 每个咒语最多被使用一次，返回最大的伤害值
// 其实也就是数组中的元素可能相同，如果使用当前元素的话，就不能使用power[i]-2,power[i]-1的值。其实算是一个很常规的动态规划题
// dp数组表示使用或不适用power[i]时的最大伤害值

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> count;
        for (int p : power) {
            count[p]++;
        }

        vector<pair<int, int>> vec;
        for (const auto& p : count) {
            vec.emplace_back(p.first, p.second);
        }

        sort(vec.begin(), vec.end());

        int n = vec.size();
        vector<long long> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = 1LL * vec[i].first * vec[i].second;
            if (i > 0) {
                int j = i - 1;
                while (j >= 0 && vec[i].first - vec[j].first <= 2) {
                    j--;
                }
                if (j >= 0) {
                    dp[i] = max(dp[i], dp[j] + 1LL * vec[i].first * vec[i].second);  // 使用当前伤害值
                }
                dp[i] = max(dp[i], dp[i - 1]);  // 不使用当前的伤害值
            }
        }

        return dp[n - 1];
    }

    using ll = long long;
    long long maximumTotalDamage1(vector<int>& power) {
        unordered_map<int, ll> count;
        for (int& i : power) {
            count[i] += i;
        }

        int n = count.size();
        vector<pair<ll, ll>> vec(n);
        int i = 0;
        for (auto& it : count) {
            vec[i++] = {it.first, it.second};
        }

        sort(vec.begin(), vec.end());

        vector<ll> dp(n);

        for (i = 0; i < n; i++) {
            dp[i] = vec[i].second;
            if (i > 0) {
                int j = i - 1;
                for (; j >= 0 && vec[i].first - vec[j].first <= 2; j--)
                    ;
                if (j >= 0) {
                    dp[i] = max(dp[i], 1LL * dp[j] + vec[i].second);
                }
                // 到目前为止都是算的使用当前值为vec[i].first的诅咒时，最大伤害有多大
                dp[i] = max(dp[i], dp[i - 1]);  //这里才是计算的如果不使用值为vec[i].first的诅咒时，最大伤害
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution st;
    vector<int> power{ 7,1,6,6 };
    cout << st.maximumTotalDamage(power) << endl;
    return 0;
}