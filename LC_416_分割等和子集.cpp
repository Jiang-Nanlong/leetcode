#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//给定一个正整数组成的非空数组，判断该数组是否可以分成两部分，这两部分的元素和相同。
//一开始并想不出这个问题怎么和背包问题联系起来，看了视频才知道。数组分割成元素和相同的两部分，这里就可以抽象为用数组中数填满sum/2大小的背包，
//这样就转化成了背包问题，而且每个元素只能用一次，所以还是01背包。不过这里的重量和价值，容量都是同一个概念
//如果最后dp[target]==target，说明恰好可以装满容量为target的背包
//这里的1 <= nums.length <= 200，1 <= nums[i] <= 100
class Solution {
public:
	bool canPartition(vector<int>& nums) {  //用一维数组做
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];

		if (sum % 2 == 1) return false;  //如果数组和本身无法分割成两个相等的部分，就返回false
		int bagsize = sum / 2;

		vector<int> dp(bagsize + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = bagsize; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);  //因为这里的重量就等于价值，所以递推公式也要相应改变
			}
		}
		if (dp[bagsize] == bagsize) return true;
		return false;
	}

	bool canPartition1(vector<int>& nums) {  //用二维数组做
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];

		if (sum % 2 == 1) return false;
		int bagsize = sum / 2;

		vector<vector<int>> dp(nums.size(), vector<int>(bagsize + 1, 0));
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j <= bagsize; j++) {
				if (j < nums[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
			}
		}
		if (dp[nums.size() - 1][bagsize] == bagsize) return true;
		return false;
	}

	//第二次做
	bool canPartition2(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		sum /= 2;
		//sort(nums.begin(), nums.end());
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = sum; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		if (dp[sum] == sum)
			return true;
		return false;
	}

	// 第三次做
	bool canPartition3(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1)
			return false;

		sum /= 2;
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = sum; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return dp[sum] == sum;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,5,11,5 };
	cout << boolalpha << st.canPartition1(nums) << endl;
	cout << st.canPartition2(nums) << endl;
	cout << st.canPartition3(nums) << noboolalpha << endl;
	return 0;
}
