
//给定一个数组，对于数组中每个元素nums[i]，统计数组中比它小的数字的数目

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
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

    //第二次做
    //其实就是记录重新排序后每个元素第一次出现的位置
    vector<int> smallerNumbersThanCurrent1(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());

        unordered_map<int, int> umap;
        for (int i = 0; i < temp.size(); i++) {
            if (umap.count(temp[i]) == 0)
                umap.insert({ temp[i], i });
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res[i] = umap[nums[i]];
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 8,1,2,2,3 };
    vector<int> res = st.smallerNumbersThanCurrent(nums);
    for (auto& i : res)
        cout << i << "  ";

    cout << endl;
    vector<int> nums1{ 8,1,2,2,3 };
    vector<int> res1 = st.smallerNumbersThanCurrent1(nums1);
    for (auto& i : res1)
        cout << i << "  ";
    return 0;
}