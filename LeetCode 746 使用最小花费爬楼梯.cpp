#include <iostream>
#include <vector>
using namespace std;

//这个题刚开始看的时候，我还是想不出怎么用动态规划做，但是看着视频里的分析，我慢慢懂了
//dp[i]代表到达第i个台阶的最小花费，那么第i个台阶可以从第i-1个台阶爬一步上来，也可以从第i-2个台阶爬两步上来，这样就很容易确定递推公式。
//因为最开始可以从第0个台阶或者第1个台阶往上跳，所以这里的dp[0]和dp[1]都初始化为0.
//本题还有一个地方需要注意，就是楼梯的顶端是在最后一个台阶之后。然后题目中每个台阶的花费其实是表示从当前台阶起跳的花费，而不是跳到这个台阶的花费。
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> dp(cost.size() + 1, 0);
		for (int i = 2; i <= cost.size(); i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[cost.size()];
	}
};

int main() {
	Solution st;
	vector<int> cost{ 1,100,1,1,1,100,1,1,100,1 };
	cout << st.minCostClimbingStairs(cost) << endl;
	return 0;
}
