#include <iostream>
#include <vector>
using namespace std;

// ����һ�������������һ������k����������������Ԫ�س˻��ϸ�С��k��������ĸ���

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)  // ��Ϊ�������СԪ�ؾ���1���˻��϶����ڵ���1������Ҫ��˻������ϸ�С��k�����k��1�Ļ�Ҳ��û������Ҫ��������
            return 0;
        int product = 1;
        int res = 0;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (product >= k) {
                product /= nums[i++];
            }
            res += j - i + 1;  // ͳ����jΪ�Ҷ˵������������ĸ���
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 10,5,2,6 };
    int k = 100;
    cout << st.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}