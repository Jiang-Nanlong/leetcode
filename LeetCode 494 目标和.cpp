#include <iostream>
#include <vector>
using namespace std;

//给定一个正整数数组和一个target，在数组中的数字前加+ -号，让数组和等于target，返回最后的组合数
//倒是看出能用回溯来做了，但是完全没看出是背包问题
// 
//回溯，回溯法写起来挺简单
class Solution {
public:
	int count = 0;
	int findTargetSumWays(vector<int>& nums, int target) {
		backtrack(nums, target, 0, 0);
		return count;
	}

	void backtrack(vector<int>& nums, int target, int startindex, int sum) {
		if (startindex == nums.size()) {
			if (sum == target)
				count++;
		}
		else {
			backtrack(nums, target, startindex + 1, sum + nums[startindex]);
			backtrack(nums, target, startindex + 1, sum - nums[startindex]);
		}
	}

	//动态规划，这个有点难
	//left组合-right组合=target  left组合+right组合=sum。所以left=(sum+target)/2
	//也就是在数组中找几个数的和等于left。就可以转化为01背包问题了，而且还都是正数，不用考虑正负号的问题。
	int findTargetSumWays1(vector<int>& nums, int target) {
		int sum = 0;
		for (int& i : nums) sum += i;
		if (abs(target) > sum) return 0;
		if ((sum + target) % 2 == 1) return 0;  //如果sum+target是奇数，就返回0
		int bagsize = (sum + target) / 2;

		vector<int> dp(bagsize + 1, 0);
		dp[0] = 1;  //这里的初始化，我有点弄不太清
		for (int i = 0; i < nums.size(); i++) {
			for (int j = bagsize; j >= nums[i]; j--) {
				dp[j] += dp[j - nums[i]];  //再就是递推公式，感觉和上楼梯的那个一样，
			}
			for (int k : dp)
				cout << k << "  ";
			cout << endl;
		}
		return dp[bagsize];
	}
};

//这个题的回溯方法比较简单，动态规划问题真难。最后对着dp数组才勉强看明白
//这个题的难点就是怎么抽象成背包问题，然后就是递推公式了
//其余的按着模版写就行
int main() {
	Solution st;
	vector<int> nums{ 1,1,1,1,1 };
	int target = 3;
	cout << st.findTargetSumWays1(nums, target) << endl;
	return 0;
}
