#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count[2] = { 0, 0 };
        int maxlen = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            count[nums[j]]++;
            while (i < j && count[0] > 1) {
                count[nums[i++]]--;
            }
            maxlen = max(maxlen, count[1]);
        }
        return maxlen == nums.size() ? maxlen - 1 : maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 0,1,1,1,0,1,1,0,1 };
    cout << st.longestSubarray(nums) << endl;
    return 0;
}