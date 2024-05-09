#include <iostream>
#include <vector>
using namespace std;

//这个题比起122和121又有要求了，这次是最多只能买卖两次，开始不懂加了这个限制以后该怎么办，看了代码随想录的pdf后才懂，感觉我一直没法自己分析出来，其实一步步分析也不算难
//因为可以至多买卖两次，所以有五种状态，0.什么都不做；1.第一次持有股票；2.第一次不持有股票；3.第二次持有股票；4.第二次不持有股票
//所以dp[i][j]表示第i天，状态j时所持有的最大价值。

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
			dp[i][0] = dp[i - 1][0];   //可以看到dp[i][0]这个状态其实可以没有
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);  //又分为前一天就持有和今天刚买入两种情况，以下几种也是这样
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
		}
		return dp[prices.size() - 1][4];
	}

	//没有dp[i][0]状态的时候
	int maxProfit1(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		dp[0][0] = -prices[0];  //第一次持有股票
		dp[0][1] = 0;  //第一次不持有股票
		dp[0][2] = -prices[0];  //第二次持有股票
		dp[0][3] = 0;  //第二次不持有股票

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
		}
		return dp[prices.size() - 1][3];
	}

	//可以观察到第i天的最大值只和i-1天有关，所以可以对dp数组进行优化
	int maxProfit2(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(4, 0));
		dp[0][0] = -prices[0];  //第一次持有股票
		dp[0][1] = 0;  //第一次不持有股票
		dp[0][2] = -prices[0];  //第二次持有股票
		dp[0][3] = 0;  //第二次不持有股票

		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
			dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1] - prices[i]);
			dp[i % 2][3] = max(dp[(i - 1) % 2][3], dp[(i - 1) % 2][2] + prices[i]);
		}
		return dp[(prices.size() - 1) % 2][3];
	}

	//第二次做，想到这几种状态了，但是把第一次持有的递推公式写错了。
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