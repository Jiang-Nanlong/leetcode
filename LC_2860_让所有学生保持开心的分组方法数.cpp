#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0] > 0;
        for (int i = 1; i < n; i++)
            if (nums[i - 1] < i && i < nums[i])
                res++;

        if (nums[n - 1] < n)
            res++;

        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 6,0,3,3,6,7,2,7 };
    cout << st.countWays(nums) << endl;
    return 0;
}