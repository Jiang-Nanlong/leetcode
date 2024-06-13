#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 这是用动态规划写的，但是超时了
    vector<bool> isArraySpecial(vector<int>& nums,
        vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (j - i == 1) {
                    dp[i][j] = (nums[i] % 2) ^ (nums[j] % 2);
                }
                else {
                    if (dp[i][j - 1] == false)
                        dp[i][j] = false;
                    else
                        dp[i][j] = (nums[j] % 2) ^ (nums[j - 1] % 2);
                }
            }
        }
        if (dp[0][n - 1]) {
            vector<bool> res(queries.size(), true);
            return res;
        }
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp.size(); j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        vector<bool> res;
        for (auto& vec : queries) {
            res.push_back(dp[vec[0]][vec[1]]);
        }
        return res;
    }

    // 用前缀和做
    vector<bool> isArraySpecial1(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> sum(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + (nums[i - 1] % 2 == nums[i] % 2);  // 当前值为0表示是奇偶交替，为1表示同种数
        }
        vector<bool> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            res[i] = sum[queries[i][1]] == sum[queries[i][0]];  // 如果相同，说明整个区间内没有1，全是0，也就都是奇偶交替的，为true，否则为false
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 4,3,1,6 };
    vector<vector<int>> queries{ {0,2},{2,3} };
    vector<bool> res = st.isArraySpecial1(nums, queries);
    cout << boolalpha;
    for (auto b : res)
        cout << b << " ";
    cout << noboolalpha << endl;
    return 0;
}