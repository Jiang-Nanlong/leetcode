#include <iostream>
#include <vector>
using namespace std;

//给定一个正整数amount，用coins数组中的元素凑成amount，每个元素可以使用无限次，这明显是个完全背包问题，最后返回组成amount的组合数
//这个题和LeetCode 494 目标和 很像，包括初始化和递推公式都一样。

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		vector<int> dp1(amount + 1, 0);
		dp1[0] = 1;
		for (int i = 0; i < coins.size(); i++) { //先物品后背包，求的是组合
			for (int j = coins[i]; j <= amount; j++) {
				dp[j] += dp[j - coins[i]];
			}
			for (int& i : dp)
				cout << i << "   ";
			cout << endl;
		}
		cout << "------------------" << endl;
		for (int j = 0; j <= amount; j++) {   //先背包后物品，求的是排列
			for (int i = 0; i < coins.size(); i++) {
				if (j >= coins[i])
					dp1[j] += dp1[j - coins[i]];
			}
			for (int& i : dp1)
				cout << i << "   ";
			cout << endl;
		}
		return dp[amount];
	}
};

/*
1   1   1   1   1   1
1   1   2   2   3   3
1   1   2   2   3   4
------------------
1   0   0   0   0   0
1   1   0   0   0   0
1   1   2   0   0   0
1   1   2   3   0   0
1   1   2   3   5   0
1   1   2   3   5   9
*/
//看j=3的时候就可以知道，先背包后物品这种情况，分别统计了2+1,1+1+1和1+2，这三种情况

int main() {
	Solution st;
	vector<int> coins{ 1,2,5 };
	int amount = 5;
	cout << st.change(amount, coins) << endl;
	return 0;
}
