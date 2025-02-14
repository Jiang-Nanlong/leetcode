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

    // ���Խ���СС���Ż������½�������value�ĺͼ�һ�𶼲���target����ô��û��Ҫ��target��ʼ��ǰ���ˣ�ֻ��Ҫ�Ӻ͵ĵط���ǰ�����
    int lengthOfLongestSubsequence1(vector<int>& nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        int s = 0;   // ��¼½�������value�ĺ�
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