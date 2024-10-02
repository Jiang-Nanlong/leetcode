#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> uset;
        int maxsum = 0, sum = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            int val = nums[j];
            while (uset.find(val) != uset.end()) {
                uset.erase(nums[i]);
                sum -= nums[i++];
            }
            sum += val;
            uset.insert(val);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 5,2,1,2,5,2,1,2,5 };
    cout << st.maximumUniqueSubarray(nums) << endl;
    return 0;
}