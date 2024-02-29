#include <iostream>
#include <vector>
using namespace std;

//和买卖股票的最佳时机III相比，这个题更一般化，这里最多买卖k次。

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2 * k, 0));
		for (int i = 0; i < 2 * k; i++)
			if (i % 2 == 0)
				dp[0][i] = -prices[0];

		for (int i = 1; i < prices.size(); i++) {
			for (int j = 0; j < 2 * k; j++) {
				if (j == 0) {
					dp[i][j] = max(dp[i - 1][j], -prices[i]);
				}
				else {
					int flag = j % 2 == 1 ? 1 : -1;
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + flag * prices[i]);
				}
			}
		}

		for (int i = 0; i < prices.size(); i++) {
			for (int j = 0; j < 2 * k; j++) {
				cout << dp[i][j] << "  ";
			}
			cout << endl;
		}
		return dp[prices.size() - 1][2 * k - 1];
	}

	//dp数组优化空间
	int maxProfit1(int k, vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(2 * k, 0));
		for (int i = 0; i < 2 * k; i++)
			if (i % 2 == 0)
				dp[0][i] = -prices[0];

		for (int i = 1; i < prices.size(); i++) {
			for (int j = 0; j < 2 * k; j++) {
				if (j == 0) {
					dp[i % 2][j] = max(dp[(i - 1) % 2][j], -prices[i]);
				}
				else {
					int flag = j % 2 == 1 ? 1 : -1;
					dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1] + flag * prices[i]);
				}
			}
		}
		return dp[(prices.size() - 1) % 2][2 * k - 1];
	}
};

int main() {
	Solution st;
	int k = 2;
	vector<int> prices{ 2,4,1 };
	cout << st.maxProfit(k, prices) << endl;
	cout << st.maxProfit1(k, prices) << endl;
	return 0;
}

