#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//给定一个数组stone，stones[i]表示第i块石头的重量，一次性从数组中取出两块石头x和y，x<=y，如果x==y，那么两块石头会被完全粉碎，
//如果x!=y，那么x会被完全粉碎，而重量为y的石头的重量变为y-x。返回最后剩余的石头重量的最小数。
//跟往常一样，看不出怎么是背包问题，看了提示才知道。完全可以抽象为在stones[i]前添加+ -号，使得最后的和最小。
//然后也可以把sum/2来当做背包，用数组中的数尽可能的填满这个背包，如果sum是偶数，且背包被填满了，那么最后就是0，如果sum是奇数，背包被填满了，那么最后是1，
//这样就转化成了背包问题，而且每个数字只能用一次，所以就是01背包
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) { //用一维数组做，跟之前一样的套路，一样的模版，但是不好理解
		int sum = 0;
		for (int& i : stones)
			sum += i;
		int target = sum / 2;
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++)
			for (int j = target; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}

		return sum - 2 * dp[target];
	}

	int lastStoneWeightII1(vector<int>& stones) {   //用二维数组做，逻辑上更清晰一些
		int sum = 0;
		for (const int& i : stones)
			sum += i;
		int bagsize = sum / 2 + 1;
		vector<vector<int>> dp(stones.size(), vector<int>(bagsize, 0));
		for (int i = stones[0]; i < bagsize; i++)
			dp[0][i] = stones[0];

		for (int i = 1; i < stones.size(); i++) {
			for (int j = 0; j < bagsize; j++) {
				if (j < stones[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
			}
		}
		return sum - dp[stones.size() - 1][bagsize - 1] * 2;
	}

	//第二次做，还是没做出来，没有想出这怎么是一个背包问题
	int lastStoneWeightII2(vector<int>& stones) {
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int target = sum / 2;
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++) {
			for (int j = target; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		return sum - 2 * dp[target];
	}

	// 第三次做，就是先统计出石头一共多沉，然后看看石头总重量一半大小的背包最多装多少。
	int lastStoneWeightII3(vector<int>& stones) {
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int bagsize = sum / 2;
		vector<int> dp(bagsize + 1, 0);
		for (int i = 0; i < stones.size(); i++) {
			for (int j = bagsize; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		return sum - 2 * dp[bagsize];
	}

};

int main() {
	Solution st;
	vector<int> stones{ 2,7,4,1,8,1 };
	cout << st.lastStoneWeightII1(stones) << endl;
	cout << st.lastStoneWeightII2(stones) << endl;
	cout << st.lastStoneWeightII3(stones) << endl;
	return 0;
}