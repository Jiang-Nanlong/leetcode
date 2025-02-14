//
// Created by cml on 25-2-14.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for (int x : nums) {
            for (int i = target; i >= x; i--) {
                dp[i] = max(dp[i], dp[i - x] + 1);
            }
        }
        return dp[target] > 0 ? dp[target] : -1;
    }

    // 可以进行小小的优化，如果陆续加入的value的和加一起都不够target，那么就没必要从target开始往前算了，只需要从和的地方往前算就行
    int lengthOfLongestSubsequence1(vector<int>& nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        int s = 0;   // 记录陆续加入的value的和
        for (int x : nums) {
            s = min(s + x, target);
            for (int i = s; i >= x; i--) {
                dp[i] = max(dp[i], dp[i - x] + 1);
            }

            for (const int y:dp)
                cout << y << ' ';
            cout << endl;
        }
        return dp[target] > 0 ? dp[target] : -1;
    }
};

int main() {
    Solution st;
    vector<int> nums{4,1,3,2,1,5};
    int target = 7;
    cout<<st.lengthOfLongestSubsequence(nums, target)<<endl;

    cout<<st.lengthOfLongestSubsequence1(nums, target)<<endl;
    return 0;
}