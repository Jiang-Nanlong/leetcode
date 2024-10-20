#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int res = 0;
        while (i < j) {
            if (nums[i] + nums[j] <= target) {
                res += j - i;
                res %= 1000000007;
                i++;
            }
            else
                j--;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,2,1,9 };
    int target = 10;
    cout << st.purchasePlans(nums, target) << endl;
    return 0;
}