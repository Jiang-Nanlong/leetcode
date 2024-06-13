#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag = nums[0] % 2;
        for (int i = 1; i < nums.size(); i++) {
            bool cur = nums[i] % 2;
            if (flag ^ cur)
                flag = cur;
            else
                return false;
        }
        return true;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,1,4 };
    cout << boolalpha << st.isArraySpecial(nums) << noboolalpha << endl;
    return 0;
}