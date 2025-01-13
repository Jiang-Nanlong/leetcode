//
// Created by ≤‹√œ¡˙ on 25-1-13.
//
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int> &nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        long long presum = 0;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            presum += nums[i];
            if (2 * presum >= sum)
                res++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{10, 4, -8, 7};
    cout << st.waysToSplitArray(nums) << endl;
    return 0;
}
