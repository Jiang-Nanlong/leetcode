#include <iostream>
#include <vector>
using namespace std;

//使用coins数组表示不同面额的硬币，用这些元素凑出amount，返回最小的硬币数，硬币可以重复使用，如果凑不出返回-1
//这个题还是常规的完全背包问题

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);  //表示凑出j所需的最小硬币数为dp[j]
		dp[0] = 0;  //因为题目中有一个示例就是这个
		for (int i = 0; i < coins.size(); i++) {   //先物品后背包
			for (int j = coins[i]; j <= amount; j++) {
				if (dp[j - coins[i]] != INT_MAX)
					dp[j] = min(dp[j], dp[j - coins[i]] + 1);   //这个题主要是递推公式难写，凑出总额为j-coins[i]的最小硬币数为dp[j-coins[i]]，
				//那么凑出总额为j的最小硬币数就是dp[j-coins[i]]+1，所以递推公式就是dp[j]=min(dp[j],dp[j]-coins[i]]+1);
			}
		}
		if (dp[amount] == INT_MAX) return -1;  //如果凑不出，返回-1
		return dp[amount];
	}


	//第二次做，这个题求组合和求排列都行
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