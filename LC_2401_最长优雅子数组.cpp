#include <iostream>
#include <vector>
using namespace std;

// ����һ������������ɵ����飬����������в�ͬλ�õ�ÿ��Ԫ�ذ�λ��Ľ��Ϊ0����Ƹ�����Ϊ����������
// ���������������ĳ��ȡ�

// ���������ѵ�������ο��ٵļ������ǰԪ���ǲ�������������֮ǰ��Ԫ�ذ�λ��������0��
// ��ʵ��������һ������_or��������ʾ������������Ԫ�ص��ڶ����Ƶ�ÿһλ�Ƿ�Ϊ1������_or|=��ǰԪ�أ��Ϳ��԰ѵ�ǰԪ�ص�ÿһλ���뵽���������
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        for (int i = 0, j = 0, _or = 0; j < nums.size(); j++) {
            while (_or & nums[j])
                _or ^= nums[i++];
            _or |= nums[j];
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 1,3,8,48,10 };
    cout << st.longestNiceSubarray(nums) << endl;
    return 0;
}