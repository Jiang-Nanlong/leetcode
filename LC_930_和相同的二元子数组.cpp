#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum1 = 0, sum2 = 0;
        int res = 0;
        for (int i1 = 0, i2 = 0, j = 0; j < nums.size(); j++) {
            sum1 += nums[j];
            sum2 += nums[j];
            while (i1 <= j && sum1 > goal)
                sum1 -= nums[i1++];

            while (i2 <= j && sum2 >= goal)
                sum2 -= nums[i2++];
            res += i2 - i1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,0,0,0,1,0,1 };
    int goal = 2;
    cout << st.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}