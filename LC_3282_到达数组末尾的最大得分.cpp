#include <iostream>
#include <vector>
using namespace std;

// ����һ������Ϊn�����飬����Ҫ���±�0��ʼ�����±�n-1��ÿ�δ��±�i���±�j�ĵ÷�Ϊ(j-i)*nums[i]
// ���ص������һ���±괦������ܵ÷�

// ���԰�j-i���ɳ����εĳ���nums[i]���ɳ����εĿ�����������ֵ
// Ҳ���԰�(j-i)*nums[i]�𿪣�nums[i]+nums[i]+nums[i]+...+nums[i]������nums[i]������С��ʱ��ͱ���ԭֵ�������������ľͱ�ɸ����

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] >= nums[i]) {
                res += 1LL * (j - i) * nums[i];
                i = j;
            }
            j++;
        }
        if (nums.back() < nums[i])
            res += 1LL * (j - i - 1) * nums[i];
        return res;
    }

    // ���ɽ�����Ĵ��룬̫�����
    long long findMaximumScore1(vector<int>& nums) {
        long long res = 0;
        int temp = 0;
        for (int i = 0; i + 1 < nums.size(); i++) {
            temp = max(temp, nums[i]);
            res += temp;
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 4,3,1,3,2 };
    cout << st.findMaximumScore(nums) << endl;
    cout << st.findMaximumScore1(nums) << endl;
    return 0;
}