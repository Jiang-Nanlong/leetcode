#include <iostream>
#include <vector>
using namespace std;

// ����һ�����������һ������k�����ĳ�������������г�����k���������֣���ô����Ϊ�����������һ������������
// �����������������Ŀ

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int count1 = 0, count2 = 0;

        for (int i1 = 0, i2 = 0, j = 0; j < nums.size(); j++) {
            count1 += (nums[j] % 2);
            count2 += (nums[j] % 2);
            while (i1 <= j && count1 > k) { // whileѭ��������count1==k
                count1 -= (nums[i1++] % 2);
            }
           
            while (i2 <= j && count2 >= k) { // whileѭ��������count1==k-1
                count2 -= (nums[i2++] % 2);
            }
            res += i2 - i1;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,1,2,1,1 };
    int k = 3;
    cout << st.numberOfSubarrays(nums, k) << endl;
    return 0;
}