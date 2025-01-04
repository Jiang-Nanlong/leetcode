#include <iostream>
#include <vector>
using namespace std;

// ·�����߸���n��λ�ã�ÿ��λ�ö����Խ����ӣ����Ƿ��Ӳ��������ڣ�·���ߵķ����໥֮����Ӱ�졣
// �ʣ�����ж����ֽ��췿�ӵķ�ʽ
// ��ʵֻ���ǵ�·һ�߾��У����ֺ�LeetCode 198 ��ҽ���һ����

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countHousePlacements(int n) {
        if (n == 1)
            return 4;
        vector<int> dp(n, 0);
        dp[0] = 2;
        dp[1] = 3;
        for (int i = 2; i < n; i++) {
            // ��i��λ�ÿ������������
            // �����i��λ�ò������ӣ���ô��i-1��λ�ÿɽ��ɲ�����dp[i]=dp[i-1];
            // �����i��λ�ý����ӣ���ô��i-1��λ�ò��ܽ�����i-2��λ�ÿɽ��ɲ�����dp[i]=dp[i-2]
            // so,dp[i]=dp[i-1]+dp[i-2]
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return (long long)dp[n - 1] * dp[n - 1] % MOD;
    }
};

int main() {
    Solution st;
    int n = 4;
    cout << st.countHousePlacements(n) << endl;
    return 0;
}