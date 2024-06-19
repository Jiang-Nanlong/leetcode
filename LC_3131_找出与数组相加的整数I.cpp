#include <iostream>
#include <vector>
using namespace std;

// ��������nums1��nums2��������ͬ��nums1�е�ÿ��Ԫ�ؼ���x�����Եõ�nums2��Ψһ��һ��Ԫ�أ�������x

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