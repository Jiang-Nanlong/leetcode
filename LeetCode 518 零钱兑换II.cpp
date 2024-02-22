#include <iostream>
#include <vector>
using namespace std;

//����һ��������amount����coins�����е�Ԫ�شճ�amount��ÿ��Ԫ�ؿ���ʹ�����޴Σ��������Ǹ���ȫ�������⣬��󷵻����amount�������
//������LeetCode 494 Ŀ��� ���񣬰�����ʼ���͵��ƹ�ʽ��һ����

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		vector<int> dp1(amount + 1, 0);
		dp1[0] = 1;
		for (int i = 0; i < coins.size(); i++) { //����Ʒ�󱳰�����������
			for (int j = coins[i]; j <= amount; j++) {
				dp[j] += dp[j - coins[i]];
			}
			for (int& i : dp)
				cout << i << "   ";
			cout << endl;
		}
		cout << "------------------" << endl;
		for (int j = 0; j <= amount; j++) {   //�ȱ�������Ʒ�����������
			for (int i = 0; i < coins.size(); i++) {
				if (j >= coins[i])
					dp1[j] += dp1[j - coins[i]];
			}
			for (int& i : dp1)
				cout << i << "   ";
			cout << endl;
		}
		return dp[amount];
	}
};

/*
1   1   1   1   1   1
1   1   2   2   3   3
1   1   2   2   3   4
------------------
1   0   0   0   0   0
1   1   0   0   0   0
1   1   2   0   0   0
1   1   2   3   0   0
1   1   2   3   5   0
1   1   2   3   5   9
*/
//��j=3��ʱ��Ϳ���֪�����ȱ�������Ʒ����������ֱ�ͳ����2+1,1+1+1��1+2�����������

int main() {
	Solution st;
	vector<int> coins{ 1,2,5 };
	int amount = 5;
	cout << st.change(amount, coins) << endl;
	return 0;
}