#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ������һ��ʼ��д�����ö�̬�滮���ܽ��������������������[2,15,14,18]�����ľͲ�����
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        vector<int> dp(rewardValues.begin(), rewardValues.end());
        int maxres = rewardValues[0];
        for (int i = 1; i < rewardValues.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] < rewardValues[i] && rewardValues[j] < rewardValues[i]) {
                    dp[i] = max(dp[i], max(rewardValues[i] + dp[j], rewardValues[i] + rewardValues[j]));
                }
                else if (dp[j] >= rewardValues[i] && rewardValues[j] < rewardValues[i])
                    dp[i] = max(dp[i], rewardValues[i] + rewardValues[j]);
                maxres = max(maxres, dp[i]);
            }
        }
        for (int i : dp)
            cout << i << " ";
        return maxres;
    }

    // ������������д���������Ǹ��������⣬��Ϊ��ĿҪ����ǵ�rewardValues[i]���ڵ�ǰ�ܽ���xʱ���Ž�rewardValues[i]����x�ϡ�
    // ����������ϱ����е���Ʒ��������С�ڱ�������
    int maxTotalReward1(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int bagsize = rewardValues.back();
        vector<int> dp(bagsize, 0);
        for (int i = 0; i < rewardValues.size(); i++) {
            for (int j = bagsize - 1; j >= rewardValues[i]; j--) {
                // ����x�Ĺ�������ؼ��ġ�
                // �����ǰԪ�ص�ֵ����ȥ����ǰԪ��ֵ�Ժ�ı�����װ���������Ͱ������ļ��㷽����
                // �����ǰԪ�ص�ֵС�ڵ���ȥ����ǰԪ��ֵ�Ժ�ı�����װ��������Ϊ�˼��ϵ�ǰԪ�أ���ôxֻ���Ǳ�ʾ����С�ڵ�ǰ���������ı�����װ�����ֵ����ôx����ֻ�ܵ���dp[rewardValues[i] - 1]
                int x = rewardValues[i] > dp[j - rewardValues[i]] ? dp[j - rewardValues[i]] : dp[rewardValues[i] - 1];
                dp[j] = max(dp[j], x + rewardValues[i]);
            }
        }
        return dp[bagsize - 1] + bagsize;
    }
};

int main() {
    Solution st;
    vector<int> rewardValues { 1, 1, 3, 3 };
    cout << st.maxTotalReward1(rewardValues) << endl;
    return 0;
}