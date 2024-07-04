#include <iostream>
#include <vector>
using namespace std;

// ����һ������������nums��ֻ��0��1������������в���������Ԫ��ֵ��ͬ��������ͳ�������������Ϊ���������飬����nums�н����������������
// ��Ϊ����Ҫ����������飬Ҳ���Ǳ�����������ġ������Ļ������һ�������鳤��Ϊ3����ô˵�����������ǽ�����ֵģ���ô�Ե�3������Ϊ��β��������͹���3������Ϊ���������Ƴ�ǰ�ߵ�Ԫ�ء�
// ���Լ�����������������ͱ���˼�����nums�е�ÿһ��Ԫ��Ϊ��β���������ǽ������������󳤶ȣ�����ٰ���Щ���ȶ���������������nums����Ľ����������������
// ��ʼ��Ϊ�Ƕ�̬�滮���������ֲ�������dp������У�ֻ��Ҫ������ǰһ��Ԫ��Ϊ��β��������ĳ��ȡ������ǰԪ�غ�ǰһ����ͬ�������¿�ʼ���������飬�����ͬ����ǰһ���ĳ����ϼ�1.

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 1;
        long long pre = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                pre = pre + 1;

            }
            else
                pre = 1;
            res += pre;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 0,1,1,1 };
    cout << st.countAlternatingSubarrays(nums) << endl;
    
    return 0;
}