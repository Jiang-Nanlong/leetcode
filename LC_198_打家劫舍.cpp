#include <iostream>
#include <vector>
using namespace std;

//不能抢相邻的两家，返回最后的能抢到金额的最大值

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		vector<int> dp(nums.size(), 0);  //dp[i]表示考虑第i家在内，能抢到的钱的最大值
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);  //dp[i]的最大值有两种情况，一是抢第i家，那么dp[i]=dp[i-2]+nums[i]；二是不抢第i家，那么dp[i]=dp[i-1]
		}
		return dp[nums.size() - 1];
	}

	//第二次做，还是没有做出来，第二次再做这个题感觉很陌生，像是没做过一样
	int rob1(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,7,9,3,1 };
	cout << st.rob(nums) << endl;
	return 0;
}