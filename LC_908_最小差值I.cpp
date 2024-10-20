#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minelem = INT_MAX, maxelem = INT_MIN;
        for (int& i : nums) {
            minelem = min(minelem, i);
            maxelem = max(maxelem, i);
        }

        int diff = maxelem - minelem;
        if (diff >= 0 && diff <= 2 * k)
            return 0;
        else
            return diff - 2 * k;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,6 };
    int k = 3;
    cout << st.smallestRangeI(nums, k) << endl;
    return 0;
}