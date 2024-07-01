#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] % k;
            for (int j = 0; j < k; j++) {
                dp[j][x] = dp[x][j] + 1;
                res = max(res, dp[j][x]);
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,3,4,5 };
    int k = 2;
    cout << st.maximumLength(nums, k) << endl;
    return 0;
}