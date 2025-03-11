//
// Created by ²ÜÃÏÁú on 25-3-11.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int> &nums) {
        int n = nums.size();
        vector<int> suffix_min(n, INT_MAX);

        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(nums[i + 1], suffix_min[i + 1]);
        }

        int res = 0;
        int pre_max = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > pre_max && nums[i] < suffix_min[i]) {
                res += 2;
            } else {
                if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                    ++res;
            }
            pre_max = max(pre_max, nums[i]);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{1, 2, 3};
    cout << st.sumOfBeauties(nums) << endl;
    return 0;
}
