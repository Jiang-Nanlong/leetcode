//
// Created by 曹孟龙 on 25-2-22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 时间复杂度为O(1)，这个题的nums[i]的范围为[0,100]，如果数据范围太大的话，可以用unordered_map替换vector
    int numIdenticalPairs(vector<int> &nums) {
        vector<int> count(101, 0);
        int res = 0;
        for (const int &i: nums) {
            res += count[i]++;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{1, 2, 3, 1, 1, 3};
    cout << st.numIdenticalPairs(nums) << endl;
    return 0;
}
