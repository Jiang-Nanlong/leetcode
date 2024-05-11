#include <iostream>
#include <vector>
using namespace std;

//给定一个nums数组，其中有一半是奇数，一般是偶数，现在把数组中奇数位调整为奇数，偶数位调整为偶数

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i % 2 == 0) {
                if (nums[i] % 2 == 0)
                    continue;
                else {
                    int begin = i + 1;
                    while (nums[begin++] % 2 == 1);
                    swap(nums[i], nums[begin - 1]);
                }
            }
            else {
                if (nums[i] % 2 == 1)
                    continue;
                else {
                    int begin = i + 1;
                    while (nums[begin++] % 2 == 0);
                    swap(nums[i], nums[begin - 1]);
                }
            }
        }
        return nums;
    }

    //这是代码随想录的答案，思路也很清晰，而且我感觉比我那个更好，但是使用了额外的空间
    vector<int> sortArrayByParityII1(vector<int>& nums) {
        vector<int> result(nums.size());
        int evenIndex = 0; // 偶数下标
        int oddIndex = 1;  // 奇数下标
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                result[evenIndex] = nums[i];
                evenIndex += 2;
            }
            else {
                result[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }
        return result;
    }

    //数组中一半奇数一半偶数，那么只要把奇数或偶数中的一种位置对应好，剩余的一种也就对应好了
    vector<int> sortArrayByParityII2(vector<int>& nums) {
        int oddIndex = 1;  //奇数下标
        for (int i = 0; i < nums.size(); i += 2) {  //只遍历数组的偶数位
            if (nums[i] % 2 == 1) {       // 如果在偶数位遇到了奇数
                while (nums[oddIndex] % 2 == 1)
                    oddIndex += 2;       // 在奇数位找一个偶数
                swap(nums[i], nums[oddIndex]); // 替换
            }
        }
    return nums;
    }

};

int main() {
    Solution st;
    vector<int> nums = { 4, 2, 5, 7 };
    vector<int> res = st.sortArrayByParityII(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    vector<int> nums1 = { 4, 2, 5, 7 };
    vector<int> res1 = st.sortArrayByParityII1(nums1);
    for (int i : res1)
        cout << i << " ";
    cout << endl;

    vector<int> nums2 = { 4, 2, 5, 7 };
    vector<int> res2 = st.sortArrayByParityII2(nums2);
    for (int i : res2)
        cout << i << " ";
    cout << endl;
    
    return 0;
}