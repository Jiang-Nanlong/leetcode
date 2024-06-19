#include <iostream>
#include <vector>
using namespace std;

// 两个数组nums1和nums2，长度相同，nums1中的每个元素加上x都可以得到nums2中唯一的一个元素，现在求x

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int minnum1 = INT_MAX, minnum2 = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            if (minnum1 > nums1[i])
                minnum1 = nums1[i];
            if (minnum2 > nums2[i])
                minnum2 = nums2[i];
        }
        return minnum2 - minnum1;
    }
};

int main() {
    Solution st;
    vector<int> nums1{ 2, 6, 4 }, nums2{ 9, 7, 5 };
    cout << st.addedInteger(nums1, nums2) << endl;
    return 0;
}