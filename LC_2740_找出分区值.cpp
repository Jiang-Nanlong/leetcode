#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            mindiff = min(mindiff, abs(nums[i] - nums[i - 1]));
        }
        return mindiff;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 100,1,10 };
    cout << st.findValueOfPartition(nums) << endl;
    return 0;
}