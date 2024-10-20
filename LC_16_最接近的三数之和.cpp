#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mindiff = 1000001;
        for (int i = 0; i < n - 2; i++) {
            int j = n - 1, k = i + 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (k < j) {
                int sum = nums[i] + nums[k] + nums[j];
                if (abs(mindiff - target) >= abs(sum - target))
                    mindiff = sum;
                if (sum < target) {
                    while (k < j && nums[k] == nums[k + 1])
                        k++;
                    k++;
                }
                else if (sum > target) {
                    while (k < j && nums[j] == nums[j - 1])
                        j--;
                    j--;
                }
                else {
                    return mindiff;
                }
            }
        }
        return mindiff;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,1,1,1 };
    int target = -100;
    cout << st.threeSumClosest(nums, target) << endl;
    return 0;
}