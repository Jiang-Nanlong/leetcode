#include <iostream>
#include <vector>
using namespace std;

//��������122��121����Ҫ���ˣ���������ֻ���������Σ���ʼ����������������Ժ����ô�죬���˴�������¼��pdf��Ŷ����о���һֱû���Լ�������������ʵһ��������Ҳ������
//��Ϊ���������������Σ�����������״̬��0.ʲô��������1.��һ�γ��й�Ʊ��2.��һ�β����й�Ʊ��3.�ڶ��γ��й�Ʊ��4.�ڶ��β����й�Ʊ
//����dp[i][j]��ʾ��i�죬״̬jʱ�����е�����ֵ��

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		dp[0][2] = 0;
		dp[0][3] = -prices[0];
		dp[0][4] = 0;

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = dp[i - 1][0];   //���Կ���dp[i][0]���״̬��ʵ����û��
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);  //�ַ�Ϊǰһ��ͳ��кͽ��������������������¼���Ҳ������
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
		}
		return dp[prices.size() - 1][4];
	}

	//û��dp[i][0]״̬��ʱ��
	int maxProfit1(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		dp[0][0] = -prices[0];  //��һ�γ��й�Ʊ
		dp[0][1] = 0;  //��һ�β����й�Ʊ
		dp[0][2] = -prices[0];  //�ڶ��γ��й�Ʊ
		dp[0][3] = 0;  //�ڶ��β����й�Ʊ

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
		}
		return dp[prices.size() - 1][3];
	}

	//���Թ۲쵽��i������ֵֻ��i-1���йأ����Կ��Զ�dp��������Ż�
	int maxProfit2(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(4, 0));
		dp[0][0] = -prices[0];  //��һ�γ��й�Ʊ
		dp[0][1] = 0;  //��һ�β����й�Ʊ
		dp[0][2] = -prices[0];  //�ڶ��γ��й�Ʊ
		dp[0][3] = 0;  //�ڶ��β����й�Ʊ

		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
			dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1] - prices[i]);
			dp[i % 2][3] = max(dp[(i - 1) % 2][3], dp[(i - 1) % 2][2] + prices[i]);
		}
		return dp[(prices.size() - 1) % 2][3];
	}

	//�ڶ��������뵽�⼸��״̬�ˣ����ǰѵ�һ�γ��еĵ��ƹ�ʽд���ˡ�
	int maxProfit3(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		dp[0][2] = -prices[0];
		dp[0][3] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
		}
		return dp[prices.size() - 1][3];
	}

};

int main() {
	Solution st;
	vector<int> prices{ 3,3,5,0,0,3,1,4 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit1(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
	return 0;
}