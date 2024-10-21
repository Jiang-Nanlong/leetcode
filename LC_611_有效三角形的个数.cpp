#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 2; i < n; i++) {
            int j = 0, k = i - 1;
            while (j < k) {
                if (nums[j] + nums[k] > nums[i]) {
                    res += k - j;
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,2,3,4 };
    cout << st.triangleNumber(nums) << endl;
    return 0;
}