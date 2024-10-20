#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                res += j - i;
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
    vector<int> nums{ -1,1,2,3,1 };
    int target = 2;
    cout << st.countPairs(nums, target) << endl;
    return 0;
}