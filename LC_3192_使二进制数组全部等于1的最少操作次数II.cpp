#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if ((nums[i] == 0 && res % 2 == 0) ||
                (nums[i] == 1 && res % 2 == 1)) {
                res++;
            }
        }

        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 0,1,1,0,1 };
    cout << st.minOperations(nums) << endl;
    return 0;
}