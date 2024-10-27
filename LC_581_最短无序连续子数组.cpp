#include <vector>
#include <iostream>
using namespace std;

// ����һ���������飬�ҳ�һ�������������飬�������������鰴����������������鶼���������
// ����������ĳ���

// �����ұ�����ά��һ�����ֵ�������ǰԪ��С�����ֵ�Ļ���˵����ǰ��ĳ��λ�ÿ�ʼ����ǰλ�ö�������ģ�
// ͬ���������������ά��һ����Сֵ�������ǰԪ�ش�����Сֵ��˵���ӵ�ǰλ�õ���ߵ�ĳ��λ�ö�������ġ�
// ���ԣ����ر����������飬�Ϳ��Էֱ�ȷ�������������˺��Ҷ�

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minnum = INT_MAX, maxnum = INT_MIN;
        int left = -1, right = -1;
        for (int i = 0; i < n; i++) {
            if (maxnum > nums[i])
                right = i;
            else
                maxnum = nums[i];

            if (minnum < nums[n - i - 1])
                left = n - i - 1;
            else
                minnum = nums[n - i - 1];
        }
        return left == -1 ? 0 : right - left + 1;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 2,6,4,8,10,9,15 };
    cout << st.findUnsortedSubarray(nums) << endl;
    return 0;
}