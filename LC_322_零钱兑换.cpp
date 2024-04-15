#include <iostream>
#include <vector>
using namespace std;

//ʹ��coins�����ʾ��ͬ����Ӳ�ң�����ЩԪ�شճ�amount��������С��Ӳ������Ӳ�ҿ����ظ�ʹ�ã�����ղ�������-1
//����⻹�ǳ������ȫ��������

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);  //��ʾ�ճ�j�������СӲ����Ϊdp[j]
		dp[0] = 0;  //��Ϊ��Ŀ����һ��ʾ���������
		for (int i = 0; i < coins.size(); i++) {   //����Ʒ�󱳰�
			for (int j = coins[i]; j <= amount; j++) {
				if (dp[j - coins[i]] != INT_MAX)
					dp[j] = min(dp[j], dp[j - coins[i]] + 1);   //�������Ҫ�ǵ��ƹ�ʽ��д���ճ��ܶ�Ϊj-coins[i]����СӲ����Ϊdp[j-coins[i]]��
				//��ô�ճ��ܶ�Ϊj����СӲ��������dp[j-coins[i]]+1�����Ե��ƹ�ʽ����dp[j]=min(dp[j],dp[j]-coins[i]]+1);
			}
		}
		if (dp[amount] == INT_MAX) return -1;  //����ղ���������-1
		return dp[amount];
	}


	//�ڶ����������������Ϻ������ж���
	int coinChange1(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); i++) {
			for (int j = coins[i]; j <= amount; j++) {
				if (dp[j - coins[i]] != INT_MAX)
					dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		if (dp[amount] == INT_MAX)
			return -1;
		return dp[amount];
	}
};

int main() {
	Solution st;
	vector<int> coins{ 1,2,5 };
	cout << st.coinChange(coins, 11) << endl;
	return 0;
}