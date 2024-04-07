#include <iostream>
#include <vector>
using namespace std;

//按说每天只有两个状态，持有股票和不持有股票,dp[i][0]表示持有股票的最大价值，dp[i][1]表示不持有股票的最大价值

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
	//上边是我写的代码，不对。
	//下边是看了代码随想录的视频，然后写的代码。这里分成了四个状态。0.持有股票；1.保持卖出股票的状态（冷静期之后未持股的状态）；2.卖出股票；3.冷静期
	//0.持有股票：可能是昨天就持有，也可能是昨天是冷静期，也可能是保持卖出股票的状态期间买入
	//1.保持卖出股票的状态：可能昨天就是保持卖出股票的状态或者昨天是冷静期
	//2.卖出股票：只能是昨天持有股票
	//3.冷静期：只能是昨天卖出股票
	//最后最大价值只可能出现在1,2,3，三种情况中。不可能出现在0种情况中

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
	//这个代码看起来很简洁，这个题的递推公式还是比较容易推的，就是最初的dp数组的状态容易难想，dp数组设不对

	//当然还可以继续优化一下dp数组
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

	//还可以进行优化，之前有四个状态，现在可以优化成三个状态：不过这个方法的初始化和冷静期的递推公式，我还有地方搞不清
	//0.持有股票的最大价值
	//1.不持有股票的最大价值（冷冻期后可以购买的状态）
	//2.不持有股票的最大价值（冷冻期）
	int maxProfit3(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
		dp[0][0] = -prices[0];
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][2] = dp[i - 1][0] + prices[i];  //但是这个冷冻期的递推公式有点搞不明白，这不就是相当于今天才卖出去吗？
		}
		return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
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
