#include <iostream>
#include <vector>
using namespace std;

// 计算一个数组中严格递增或严格递减的子数组的最大长度

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {  // 计算严格递增的最大长度
            if (nums[i] > nums[i - 1]) {
                len++;
                maxlen = max(maxlen, len);
            }
            else {
                len = 1;
            }
        }


        len = 1;
        for (int i = 1; i < nums.size(); i++) {  // 严格递减的最大长度
            if (nums[i] < nums[i - 1]) {
                len++;
                maxlen = max(maxlen, len);
            }
            else {
                len = 1;
            }
        }

        return maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,4,3,3,2 };
    cout << st.longestMonotonicSubarray(nums) << endl;
    return 0;
}