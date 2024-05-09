#include <iostream>
#include <vector>
using namespace std;

//��˵ÿ��ֻ������״̬�����й�Ʊ�Ͳ����й�Ʊ,dp[i][0]��ʾ���й�Ʊ������ֵ��dp[i][1]��ʾ�����й�Ʊ������ֵ

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		int day = -1;
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);

			if (dp[i - 1][1] - prices[i] > dp[i - 1][0] && day < i - 1) {
				dp[i][0] = dp[i - 1][1] - prices[i];
			}
			else
				dp[i][0] = dp[i - 1][0];

			if (dp[i - 1][0] + prices[i] > dp[i - 1][1]) {
				day = i;
				dp[i][1] = dp[i - 1][0] + prices[i];
			}
			else
				dp[i][1] = dp[i - 1][1];


		}

		for (int i = 0; i < prices.size(); i++)
			cout << dp[i][0] << "  " << dp[i][1] << endl;

		return dp[prices.size() - 1][1];
	}
	//�ϱ�����д�Ĵ��룬���ԡ�
	//�±��ǿ��˴�������¼����Ƶ��Ȼ��д�Ĵ��롣����ֳ����ĸ�״̬��0.���й�Ʊ��1.����������Ʊ��״̬���侲��֮��δ�ֹɵ�״̬����2.������Ʊ��3.�侲��
	//0.���й�Ʊ������������ͳ��У�Ҳ�������������侲�ڣ�Ҳ�����Ǳ���������Ʊ��״̬�ڼ�����
	//1.����������Ʊ��״̬������������Ǳ���������Ʊ��״̬�����������侲��
	//2.������Ʊ��ֻ����������й�Ʊ
	//3.�侲�ڣ�ֻ��������������Ʊ
	//�������ֵֻ���ܳ�����1,2,3����������С������ܳ�����0�������

	int maxProfit1(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		dp[0][2] = 0;
		dp[0][3] = 0;

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
			dp[i][2] = dp[i - 1][0] + prices[i];
			dp[i][3] = dp[i - 1][2];
		}
		return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
	}
	//������뿴�����ܼ�࣬�����ĵ��ƹ�ʽ���ǱȽ������Ƶģ����������dp�����״̬�������룬dp�����費��

	//��Ȼ�����Լ����Ż�һ��dp����
	int maxProfit2(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(4, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		dp[0][2] = 0;
		dp[0][3] = 0;

		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], max(dp[(i - 1) % 2][3] - prices[i], dp[(i - 1) % 2][1] - prices[i]));
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][3]);
			dp[i % 2][2] = dp[(i - 1) % 2][0] + prices[i];
			dp[i % 2][3] = dp[(i - 1) % 2][2];
		}
		return max(dp[(prices.size() - 1) % 2][1], max(dp[(prices.size() - 1) % 2][2], dp[(prices.size() - 1) % 2][3]));
	}

	//�����Խ����Ż���֮ǰ���ĸ�״̬�����ڿ����Ż�������״̬��������������ĳ�ʼ�����侲�ڵĵ��ƹ�ʽ���һ��еط��㲻��
	//0.���й�Ʊ������ֵ
	//1.�����й�Ʊ������ֵ���䶳�ں���Թ����״̬��
	//2.�����й�Ʊ������ֵ���䶳�ڣ�
	int maxProfit3(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
		dp[0][0] = -prices[0];
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][2] = dp[i - 1][0] + prices[i];  //��������䶳�ڵĵ��ƹ�ʽ�е�㲻���ף��ⲻ�����൱�ڽ��������ȥ��
		}
		return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
	}

	//�ڶ����������Լ�Ҳ��д��������״̬�ˣ�����û���Լ�д�����ȥ������
	int maxProfit4(vector<int>& prices) {
		if (prices.size() == 1)
			return 0;
		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		// 0 ���й�Ʊ
		// 1 ����������Ʊ��״̬
		// 2 ����������Ʊ
		// 3 �䶳��
		dp[0][0] = -prices[0];

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
			dp[i][2] = dp[i - 1][0] + prices[i];
			dp[i][3] = dp[i - 1][2];
		}
		return max(dp[prices.size() - 1][3],
			max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
	}
};

int main() {
	Solution st;
	vector<int> prices{ 1,2,3,0,2 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit1(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
	cout << st.maxProfit3(prices) << endl;
	return 0;
}