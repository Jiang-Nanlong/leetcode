#include <iostream>
#include <vector>
using namespace std;

// ����һ���������ϸ�������ϸ�ݼ������������󳤶�

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {  // �����ϸ��������󳤶�
            if (nums[i] > nums[i - 1]) {
                len++;
                maxlen = max(maxlen, len);
            }
            else {
                len = 1;
            }
        }


        len = 1;
        for (int i = 1; i < nums.size(); i++) {  // �ϸ�ݼ�����󳤶�
            if (nums[i] < nums[i - 1]) {
                len++;
                maxlen = max(maxlen, len);
            }
            else {
                len = 1;
            }
        }

        return maxlen;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,4,3,3,2 };
    cout << st.longestMonotonicSubarray(nums) << endl;
    return 0;
}