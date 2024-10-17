#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> mp;
        int maxlen = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            while (mp.rbegin()->first - mp.begin()->first > limit) {
                if (--mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 8,2,4,7 };
    int limit = 4;
    cout << st.longestSubarray(nums, limit) << endl;
    return 0;
}