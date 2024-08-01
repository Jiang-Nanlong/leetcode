#include <iostream>
#include <vector>
using namespace std;

// low��high��ʾһ������ұ����䣬zero��ʾÿ�ο������ַ���ĩβ����zero��0��one��ʾÿ�ο������ַ���ĩβ����one��1��
// ���㹹�쳤����low��high֮����ַ������ж����ֹ��췽���������1e9+7ȡ��

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);  // dp[i]��ʾ���쳤��Ϊi���ַ����ķ�ʽ��
        int mod = 1e9 + 7;
        dp[0] = 1;
        int res = 0;
        for (int i = 1; i <= high; i++) {
            if (i >= zero)  // �����ǰ�ַ������ȴ��ڵ���zero���������i-zeroĩβ����zero��0�������
                dp[i] = dp[i - zero];
            if (i >= one)   // �����ǰ�ַ������ȴ��ڵ���one���������i-oneĩβ����one��1�������
                dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= low)
                res = (res + dp[i]) % mod;
        }
        return res;
    }
};

int main() {
    Solution st;
    int low = 3, high = 3, zero = 1, one = 1;
    cout << st.countGoodStrings(low, high, zero, one) << endl;
    return 0;
}