#include <iostream>
#include <vector>
using namespace std;

//这个题刚开始接触比较难想出递推公式。但是转变思路一想，每次可以跳1或2个台阶，那么也就是可以从i-1跳一个台阶上来，或者是从i-2跳两个台阶上来，
//这样递推公式就很明了了，dp[i]=dp[i-1]+dp[i-2]
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2) return n;
		vector<int> dp(n + 1);
		dp[1] = 1, dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

	//第二次做，现在看来已经是比较简单好理解的了
	int climbStairs1(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
};

int main() {
	Solution st;
	cout << st.climbStairs(4) << endl;
	return 0;
}