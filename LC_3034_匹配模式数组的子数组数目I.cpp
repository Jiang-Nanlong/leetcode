#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int m = pattern.size(), n = nums.size();
        int res = 0;
        for (int i = 0; i < n - m; ++i) {
            bool flag = true;
            for (int k = 0; k < m; ++k) {
                if (pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) {
                    flag = false;
                    break;
                }
                else if (pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) {
                    flag = false;
                    break;
                }
                else if (pattern[k] == -1 && nums[i + k + 1] >= nums[i + k]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,4,4,1,3,5,5,3 }, pattern{ 1,0,-1 };
    cout << st.countMatchingSubarrays(nums, pattern) << endl;
    return 0;
}