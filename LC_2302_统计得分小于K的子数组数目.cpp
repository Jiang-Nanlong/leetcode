#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0, res = 0;
        long long pre_sum = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            pre_sum += nums[j];
            sum = pre_sum * (j - i + 1);
            while (sum >= k) {
                pre_sum -= nums[i++];
                sum = pre_sum * (j - i + 1);
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,1,4,3,5 };
    int k = 10;
    cout << st.countSubarrays(nums, k) << endl;
    return 0;
}