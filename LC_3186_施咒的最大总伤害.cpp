#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// power����ÿ��Ԫ�ر�ʾһ��������˺�ֵ�������ж����������ͬ���˺�ֵ�����ʹ�����˺�ֵΪpower[i]������ʱ�����ǾͲ���ʹ���˺�ֵΪpower[i]-2,power[i]-1,power[i]+1,power[i]+2������
// ÿ��������౻ʹ��һ�Σ����������˺�ֵ
// ��ʵҲ���������е�Ԫ�ؿ�����ͬ�����ʹ�õ�ǰԪ�صĻ����Ͳ���ʹ��power[i]-2,power[i]-1��ֵ����ʵ����һ���ܳ���Ķ�̬�滮��
// dp�����ʾʹ�û�����power[i]ʱ������˺�ֵ

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> count;
        for (int p : power) {
            count[p]++;
        }

        vector<pair<int, int>> vec;
        for (const auto& p : count) {
            vec.emplace_back(p.first, p.second);
        }

        sort(vec.begin(), vec.end());

        int n = vec.size();
        vector<long long> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = 1LL * vec[i].first * vec[i].second;
            if (i > 0) {
                int j = i - 1;
                while (j >= 0 && vec[i].first - vec[j].first <= 2) {
                    j--;
                }
                if (j >= 0) {
                    dp[i] = max(dp[i], dp[j] + 1LL * vec[i].first * vec[i].second);  // ʹ�õ�ǰ�˺�ֵ
                }
                dp[i] = max(dp[i], dp[i - 1]);  // ��ʹ�õ�ǰ���˺�ֵ
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution st;
    vector<int> power{ 7,1,6,6 };
    cout << st.maximumTotalDamage(power) << endl;
    return 0;
}