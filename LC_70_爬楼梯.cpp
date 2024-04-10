#include <iostream>
#include <vector>
using namespace std;

//�����տ�ʼ�Ӵ��Ƚ���������ƹ�ʽ������ת��˼·һ�룬ÿ�ο�����1��2��̨�ף���ôҲ���ǿ��Դ�i-1��һ��̨�������������Ǵ�i-2������̨��������
//�������ƹ�ʽ�ͺ������ˣ�dp[i]=dp[i-1]+dp[i-2]
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n;
		vector<int> dp(n + 1);
		dp[1] = 1, dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

	//�ڶ����������ڿ����Ѿ��ǱȽϼ򵥺�������
	int climbStairs1(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
};

int main() {
	Solution st;
	cout << st.climbStairs(4) << endl;
	return 0;
}