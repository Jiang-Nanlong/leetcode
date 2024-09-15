#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
            });

        int left = nums[0][0], right = nums[0][1];
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (right >= nums[i][0])
                right = max(right, nums[i][1]);
            else {
                count += right - left + 1;
                left = nums[i][0];
                right = nums[i][1];
            }
        }
        count += right - left + 1;
        return count;
    }
};

int main() {
    Solution st;
    vector<vector<int>> nums{ {1,3},{5,8} };
    cout << st.numberOfPoints(nums);
    return 0;
}