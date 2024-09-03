#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ����������nums����nums����ѡԪ�أ�����ЩԪ�صĳ˻���󣬷���������˻�

class Solution {
public:
    // �������Լ�д�ģ��Ȱ�����ֵ����Ȼ��ͳ���ж��ٸ�С��0�����������ż�����Ͱ����������з�0Ԫ�ض���������
    // ��������������Ͱ������0�����������������������Ǹ�����
    long long maxStrength(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end(),
            [](const int& a, const int& b) { return abs(a) > abs(b); });
        int count = 0;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                count++;
                index = i;
            }
        }
        long long res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (count % 2 == 0) {
                if (res == INT_MIN)
                    res = nums[i];
                else if (nums[i] != 0)
                    res *= nums[i];
            }
            else {
                if (i == index)
                    continue;
                if (res == INT_MIN)
                    res = nums[i];
                else if (nums[i] != 0)
                    res *= nums[i];
            }
        }
        return res;
    }

    // ���ǿ������ɽ�����Ĵ�
    // ���������е�ÿ��Ԫ�ض������������ѡ or ��ѡ��
    // ��ѡ������£�nums[i]���������Ϊһ�����ֵ�����nums[i]>0����ônums[i]����ǰ��Ԫ�س˻������ֵ���Ի�����ֵ��
    // ���nums[i]<0����ônums[i]����ǰ��Ԫ�س˻�����Сֵ���Ի�����ֵ��
    // ������������ֻ��Ҫά����������������ѡԪ�س˻������ֵ����Сֵ���ɡ�

    long long maxStrength1(vector<int>& nums) {
        long long mn = nums[0], mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            long long temp = mn;  // ��߻���������Сֵ������Ҫ�ȱ���һ��
            mn = min({ mn, x, mn * x, mx * x });  // ��Сֵ���Դ����ĸ�ѡ����ѡ��
            mx = max({ mx, x, temp * x, mx * x });  // ���ֵ���Դ����ĸ�ѡ����ѡ��
        }
        return mx;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 3,-1,-5,2,5,-9 };
    cout << st.maxStrength(nums) << endl;
    cout << st.maxStrength1(nums) << endl;
    return 0;
}