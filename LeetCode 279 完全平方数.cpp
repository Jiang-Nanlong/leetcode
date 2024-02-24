#include <iostream>
#include <vector>
using namespace std;

//给定一个整数，用平方数的和表示它，返回最小的平方数的个数
//除了平方的地方之外，其余的都和LeetCode 322 零钱兑换一样
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i * i <= n; i++) {
			for (int j = i * i; j <= n; j++)
				dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
		return dp[n];
	}
};

int main() {
	Solution st;
	cout << st.numSquares(12) << endl;
	return 0;
}