#include <iostream>
#include <vector>
using namespace std;

//给定一个整数数组，和一个target，从数组中找出数来凑成target，数字可以重复使用。这一看就是一个完全背包的问题
//另外题目有一个要求，题目数据保证答案符合 32 位整数范围
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int j = 0; j <= target; j++) {
			for (int i = 0; i < nums.size(); i++) {
				if (j >= nums[i] && (long long)dp[j] + dp[j - nums[i]] < INT_MAX)  //这个判断后边条件是因为测试用例中有超过32位整数范围的数，
					//而题目又要求答案都符合32位整数范围，所以超过32位证书范围的数就直接不用考虑了
					dp[j] += dp[j - nums[i]];
			}
		}
		return dp[target];
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,3 };
	int target = 4;
	cout << st.combinationSum4(nums, target) << endl;
	return 0;
}
