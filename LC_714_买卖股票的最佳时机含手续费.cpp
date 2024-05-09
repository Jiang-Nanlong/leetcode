#include <iostream>
#include <vector>
using namespace std;

//可以进行多次交易，不过每次交易的时候都需要交手续费fee。
//这个题和LeetCode 122 买卖股票的最佳时机II 一样，只要在卖出的时候减去手续费就行
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

	//优化dp数组
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
