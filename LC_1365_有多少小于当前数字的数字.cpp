
//给定一个数组，对于数组中每个元素nums[i]，统计数组中比它小的数字的数目

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int hash[101] = { 0 };
        for (int i = 0; i < temp.size(); i++) { //这里是从前往后遍历的，遇到相同的直接跳过，其实还可以从后向前遍历，遇到相同的也被前边的那个给覆盖了
            if (i > 0 && temp[i] == temp[i - 1]) continue;
            hash[temp[i]] = i;
        }
        //或者写成这样
        /*for (int i = nums.size() - 1; i >= 0; i--) {
            hash[temp[i]] = i;
        }*/

        for (auto& i : nums) {
            i = hash[i];
        }
        return nums;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 8,1,2,2,3 };
    vector<int> res = st.smallerNumbersThanCurrent(nums);
    for (auto& i : res)
        cout << i << "  ";
    return 0;
}