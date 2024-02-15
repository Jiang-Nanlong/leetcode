#include <iostream>
#include <vector>
using namespace std;

//����ⲻ�ö�̬�滮Ҳ��������Ҫ��������Ϥ��̬�滮���������
//1��ȷ��dp�����Լ��±�ĺ���
//2��ȷ�����ƹ�ʽ
//3��dp������γ�ʼ��
//4��ȷ������˳��
//5�������Ƶ�dp����

class Solution {
public:
	int fib(int n) {
		if (n <= 1) return n;
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}

	//��ʵ���ﲻ������n����С��������У����Կ���ÿ��λ�õ�쳲�������ֻ����֮ǰ���������й�
	int fib1(int n) {
		if (n <= 1) return n;
		int dp[2];
		dp[0] = 0, dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			int sum = dp[0] + dp[1];
			dp[0] = dp[1];
			dp[1] = sum;
		}
		return dp[1];
	}
};

int main() {
	Solution st;
	int n = 4;
	cout << st.fib(4) << endl;
	cout << st.fib1(4) << endl;
	return 0;
}