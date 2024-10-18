#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                res++;
                for (int j = 0; j < 3; j++) {
                    nums[i + j] = nums[i + j] == 0 ? 1 : 0;
                }
            }
        }
        if (nums[n - 1] == 0 || nums[n - 2] == 0)
            return -1;
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 0,1,1,1,0,0 };
    cout << st.minOperations(nums) << endl;
    return 0;
}