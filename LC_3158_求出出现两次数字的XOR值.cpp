#include <iostream>
#include <vector>
using namespace std;

// ����һ�����飬�����е�����Ҫô��������Ҫô����һ�Σ��������������г������ε����ֵ�XORֵ
// ���鳤�Ⱥ����������ֵĳ��ȶ���[1,50]

class Solution {
public:
    // һ��ʼ�Լ����ģ���������򵥵ķ���
    int duplicateNumbersXOR(vector<int>& nums) {
        int cnt[51];
        memset(cnt, 0, sizeof(cnt));
        for (int i : nums)
            cnt[i]++;

        int res = 0;
        for (int i = 1; i < 51; i++)
            if (cnt[i] == 2)
                res ^= i;

        return res;
    }

    // ע�⵽���ֵķ�Χ����ȫ������һ��longlong�͵������е�ÿһλ��ʾÿ�����ֵĳ��ִ���
    int duplicateNumbersXOR1(vector<int>& nums) {
        int res = 0;
        long long cnt = 0;
        for (int i : nums) {
            if (cnt >> i & 1)  // ���ֵΪi�������Ѿ����ֹ��ˣ���ô˵�����ǵڶ��γ��֣���Ϊһ������Ҫô����һ�Σ�Ҫô��������
                res ^= i;
            else
                cnt |= 1LL << i;  // ����ͼ��뵽longlong����ȥ
        }
        return res;
    }
};

int main() {
    Solution st;
    vector<int> nums{ 10,18,7,10,18 };
    cout << st.duplicateNumbersXOR(nums) << endl;
    cout << st.duplicateNumbersXOR1(nums) << endl;
    return 0;
}