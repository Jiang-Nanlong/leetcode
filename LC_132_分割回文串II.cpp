#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <climits>
using namespace std;

// ����һ���ַ��������ַ����и��һ�������Ӵ���ÿ���Ӵ�����һ�����Ĵ����������и��

class Solution {
public:
    //�������Լ�д�Ĵ��룬���ԡ��ҿ�ʼ���������dp���飬Ȼ������������֮ǰ��������·����С������Ҳ�����㸲�ǵ�˼·�������ǲ��С�
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        stack<int> stk;  //����ջ
        for (int i = 0; i < n; i++) {
            int cover = i;
            for (int j = i; j < n; j++) {
                if (dp[i][j]) {
                    cover = j;
                }
            }
            if (stk.empty() || cover > stk.top()) stk.push(cover);
            if (cover == n - 1) break;
        }
        return stk.size()-1;
    }

    //��������¼�Ĵ�
    int minCut1(string s) {
        int n = s.size();
        vector<vector<bool>> ispalindrome(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {  //������LeetCode 5��LeetCode647�����⣬�����ԭ����dp���飬Ҳ���ǿ�[i,j]�ǲ���һ�������Ӵ�
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || ispalindrome[i + 1][j - 1]))
                    ispalindrome[i][j] = true;
            }
        }

        vector<int> dp(n, INT_MAX);//dp[i]��ʾ��[0,i]���ַ����и�ɻ����Ӵ���������ٵ��������ﻹ���԰�dp[i]��ʼ����i����Ϊdp[i]�и�ɻ��Ĵ����Ҳ����ÿ����ĸ��һ��Ҳ����i��
        for (int i = 0; i < n; i++) {
            if (ispalindrome[0][i]) {  //���[0,i]�������ǻ��Ĵ���dp[i]����Ϊ0
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (ispalindrome[j + 1][i])  //���[j+1,i]Ϊ���Ĵ�����ôdp[i]=dp[j]+1,Ҳ���Ǵ�j�Ļ���������һ���Ϳ���
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }

    int minCut2(string s) {
        int n = s.size();
        vector<vector<bool>> isValid(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || isValid[i + 1][j - 1]))
                    isValid[i][j] = true;
            }
        }

        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            if (isValid[0][i]) {
                continue;
            }
            int res = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isValid[j + 1][i])
                    res = min(res, dp[j] + 1);
            }
            dp[i] = res;
        }
        return dp[n - 1];
    }
};

int main() {
    Solution st;
    string s("cabababcbc");
    cout << st.minCut1(s) << endl;
    return 0;
}