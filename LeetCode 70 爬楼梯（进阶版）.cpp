#include<iostream>
#include <vector>
using namespace std;

//����LeetCode 70 ��¥�ݵĽ��װ棬ԭ����һ��������1��2��̨�ף������Ϊһ��������1��̨�ף�2��̨�ף�3��̨�ס�����ֱ��m��̨�ף�
//���ж����ֲ�ͬ�ķ�������¥��
//��һ������һ����ȫ�������⣬���һ���һ�������е�����
class Solution {
public:
	int climbStairs(int n, int m) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i >= j)
					dp[i] += dp[i - j];
			}
		}
		return dp[n];
	}
};

int main() {
	Solution st;
	int n = 3, m = 2;  //m=2ʱ���ԭ��
	cout << st.climbStairs(n, m) << endl;
	return 0;
}