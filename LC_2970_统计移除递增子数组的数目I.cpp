#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (isValid(nums, i, j))
                    res++;
            }
        }
        return res;
    }
    bool isValid(vector<int>& nums, int begin, int end) {
        for (int i = 1; i < begin; i++) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        if (end + 1 < nums.size() && begin - 1 >= 0)
            if (nums[end + 1] <= nums[begin - 1])
                return false;
        for (int i = end + 2; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,2,3,4 };
    cout << st.incremovableSubarrayCount(nums) << endl;

    return 0;
}