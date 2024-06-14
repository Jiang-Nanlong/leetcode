#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ����һ�����������飬�����е���������λ����ͬ������Ҫͳ������֮����ͬ��λ�ϲ�ͬ���ֵ���Ŀ�͡�
// ������˼·��ÿ����λ�ֿ�ͳ�ơ�
// ���赱ǰ���е����ֶ���һλ������ô��������i��Ԫ��ʱ����i��Ԫ����֮ǰ���������ֲ���ͬ�ĸ����͵���i��ȥ֮ǰ���i������ͬ��Ԫ������ʣ�µľ��Ƕ�����ͬ�������ˣ�
// ÿһ�����i��������϶��ǲ���ͬ�ġ��ŵ���λ���У�Ҳ��һ���ġ�

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long res = 0;
        int n = to_string(nums[0]).size();  // �Ⱦ����м�λ��
        vector<vector<int>> vec(n, vector<int>(10, 0));  // Ϊÿһ����λ������һ��vector��ͳ��ÿ�����ֳ��ֵĴ���
        for (int i = 0; i < nums.size(); i++) {  // ��i������
            int num = nums[i];
            for (int j = 0; num; num /= 10, j++) {  // ��j����λ
                int x = num % 10;
                res += i - vec[j][x];   // i��ȥͬһ����λ��֮ǰ���iλ��ͬ�����ֵĸ��������ǲ�ͬ���Եĸ���
                vec[j][x]++;
            }
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 13,23,12 };
    cout << st.sumDigitDifferences(nums) << endl;
    return 0;
}