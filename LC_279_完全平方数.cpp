#include <iostream>
#include <vector>
using namespace std;

//����һ����������ƽ�����ĺͱ�ʾ����������С��ƽ�����ĸ���
//����ƽ���ĵط�֮�⣬����Ķ���LeetCode 322 ��Ǯ�һ�һ��
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++)
                dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
        return dp[n];
    }

    //�ڶ������������n���ڵ�������ȫƽ������Ϊ��Ʒ�������������������Ժ��ٿ���ǰ�Ĵ��룬����֮ǰ�ĸ��򵥡�
    int numSquares1(int n) {
        vector<int> num;
        for (int i = 1; i <= n; i++) {
            if (sqrt(i) == (int)sqrt(i)) {
                num.push_back(i);
            }
        }
        int count = num.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < count; i++) {
            for (int j = num[i]; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - num[i]] + 1);
            }
        }
        return dp[n];
    }

    //�����������������
    int numSquares2(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution st;
    cout << st.numSquares(12) << endl;
    cout << st.numSquares1(12) << endl;
    cout << st.numSquares2(12) << endl;
    return 0;
}