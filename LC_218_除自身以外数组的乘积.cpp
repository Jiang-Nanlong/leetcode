//
// Created by 曹孟龙 on 25-3-31.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        vector<int> suffix(n, 1);
        int prefix = 1;
        for (int i = n; i >= 0; i--)
            if (i < n - 1)
                suffix[i] = nums[i + 1] * suffix[i + 1];

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = prefix * suffix[i];
            prefix *= nums[i];
        }
        return res;
    }

    vector<int> productExceptSelf1(vector<int> &nums) {
        int n = nums.size();
        vector<int> suffix(n, 1);
        int prefix = 1;
        for (int i = n; i >= 0; i--)
            if (i < n - 1)
                suffix[i] = nums[i + 1] * suffix[i + 1];

        // 或者可以用后缀数组作为返回的数组
        for (int i = 0; i < n; i++) {
            suffix[i] = prefix * suffix[i];
            prefix *= nums[i];
        }
        return suffix;
    }
};

int main() {
    Solution st;
    vector<int> nums{1, 2, 3, 4};
    vector<int> res = st.productExceptSelf(nums);
    for (int i: res)
        cout << i << " ";
    cout << endl;
    return 0;
}
