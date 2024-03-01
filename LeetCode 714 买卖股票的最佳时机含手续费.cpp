#include <iostream>
#include <vector>
using namespace std;

//���Խ��ж�ν��ף�����ÿ�ν��׵�ʱ����Ҫ��������fee��
//������LeetCode 122 ������Ʊ�����ʱ��II һ����ֻҪ��������ʱ���ȥ�����Ѿ���
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0];
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
		}
		return dp[prices.size() - 1][1];
	}

	//�Ż�dp����
	int maxProfit1(vector<int>& prices, int fee) {
		vector<vector<int>> dp(2, vector<int>(2, 0));
		dp[0][0] = -prices[0];
		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i] - fee);
		}
		return dp[(prices.size() - 1) % 2][1];
	}
};

int main() {
	Solution st;
	vector<int> prices{ 1, 3, 2, 8, 4, 9 };
	int fee = 2;
	cout << st.maxProfit(prices, fee) << endl;
	cout << st.maxProfit1(prices, fee) << endl;
	return 0;
}