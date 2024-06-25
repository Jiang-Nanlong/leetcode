#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double minelem = DBL_MAX;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            double temp = (nums[left++] + nums[right--]) / 2.0;
            minelem = min(minelem, temp);
        }
        return minelem;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 7,8,3,4,15,13,4,1 };
    cout << st.minimumAverage(nums) << endl;
    return 0;
}