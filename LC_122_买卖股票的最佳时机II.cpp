#include <iostream>
#include <vector>
using namespace std;

//整数数组prices中的prices[i]表示某只股票第i天的价格，每天都可以买卖股票，返回最大利润
//这个题用贪心算法还算比较简单，只有有钱就赚，不一定非得把股票在手上攒好几天，遇到高价才卖。
//只要今天的价格相对于买价有得赚就卖
//从贪心算法的角度也好理解，局部最优：每天都有钱赚  全局最优：获得最大利润

//这个题和LeetCode 121 买卖股票的最佳时机的区别就是这个题可以买卖多次，而121题只能买卖一次

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buy = prices[0];
		int result = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < buy)
				buy = prices[i];
			else {
				result = result + prices[i] - buy;
				buy = prices[i];
			}
		}
		return result;
	}

	//简化成一下代码
	int maxProfit1(vector<int>& prices) {
		int buy = prices[0];
		int result = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] > buy)
				result = result + prices[i] - buy;
			buy = prices[i];
		}
		return result;
	}

	//下边是代码随想录的代码，它是从第2天开始算起，好像他的更直观
	int maxProfit2(vector<int>& prices) {
		int result = 0;
		for (int i = 1; i < prices.size(); i++) {
			result += max(prices[i] - prices[i - 1], 0);
		}
		return result;
	}

	//动态规划做，dp[i][0]表示第i天持有股票的最大价值，dp[i][1]表示第i天不持有股票的最大价值
	int maxProfit3(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);  //这个题和上一题递推公式的唯一区别就在这，第i天买股票的时候，手头的最大价值不再是 -prices[i]，而是dp[i-1][1]-prices[i]
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		return dp[prices.size() - 1][1];
	}

	//还和121题一样可以对dp数组进行优化
	int maxProfit4(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
		}
		return dp[(prices.size() - 1) % 2][1];
	}
};

void main() {
	Solution st;
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
	cout << st.maxProfit3(prices) << endl;
	cout << st.maxProfit4(prices) << endl;
}
