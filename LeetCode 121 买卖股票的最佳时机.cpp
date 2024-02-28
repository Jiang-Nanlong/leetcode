#include <iostream>
#include <vector>
using namespace std;

//这个题的分析过程特别巧妙，我只想到了要用二维的dp数组，一维表示买入股票的最大价值，一维表示不买入的最大价值
//看完题解以后发现不是这样的，dp[i][0]表示持有股票的最大价值，dp[i][1]表示不持有股票的最大价值
//持有股票可以分为今天持有和今天买入两种情况，不持有可以分为今天不持有和今天卖出两种情况。
//最后返回最后一天不持有股票的最大价值
//这个题只能买卖一次股票，而LeetCode 122 买卖股票的最佳时机II可以买卖多次
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], -prices[i]);  //今天持有
			dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);   //今天不持有
		}
		return dp[prices.size() - 1][1];
	}

	//观察递推公式可以发现当天的最大价值只与前一天有关，所以dp数组只需要两天即可。
	int maxProfit1(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);  //这里的i%2和（i-1）%2，真是巧妙，我总想着要把今天的值重新赋给前一天，没想到用i%2可以直接交替使用两天的数据
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
		}
		return dp[(prices.size() - 1) % 2][1];
	}

	//这题还能用贪心做，贪心无非就是最低价买入，最高价卖出
	int maxProfit2(vector<int>& prices) {
		int low = INT_MAX;
		int result = 0;
		for (int i = 0; i < prices.size(); i++) {
			low = min(low, prices[i]);
			result = max(result, prices[i] - low);
		}
		return result;
	}
};

int main() {
	Solution st;
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit1(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
	return 0;
}