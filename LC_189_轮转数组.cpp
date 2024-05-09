#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �������е�Ԫ��������תk��λ�ã�kΪ�Ǹ�����
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();  // k���ܴ�������ĳ���
        Solution::reverse(nums, 0, nums.size() - k - 1);
        Solution::reverse(nums, nums.size() - k, nums.size() - 1);
        Solution::reverse(nums, 0, nums.size() - 1);
    }

    void reverse(vector<int>& nums, int begin, int end) {
        while (begin <= end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }
    }

    //������ֱ��ʹ��C++�Դ���reverse����
    void rotate1(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.begin() + nums.size() - k);
        std::reverse(nums.begin() + nums.size() - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution st;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3;
    st.rotate(nums, k);
    for (int i : nums)
        cout << i << "  ";
    cout << endl;
    vector<int> nums1 = { 1, 2, 3, 4, 5, 6, 7 };
    st.rotate(nums1, k);
    for (int i : nums1)
        cout << i << "  ";
    return 0;
}