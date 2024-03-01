#include <iostream>
#include <vector>
using namespace std;

//这个题和LeetCode 300 最长递增子序列不一样，这个题的要求的递增子序列是连续的，这样就好做了，只需要把nums[i]和nums[i-1]进行比较就行了
//再就是和LeetCode 300一样，最大的结果不一定出现在dp[nums.size()-1]，可能出现在dp数组的任何地方

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		int res = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			}
			res = max(res, dp[i]);
		}
		return res;
	}

	//这个题还可以用贪心来做
	int findLengthOfLCTIS1(vector<int>& nums) {
		int res = 1, count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1])
				count++;
			else
				count = 1;
			if (count > res) res = count;
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,3,5,4,7 };
	cout << st.findLengthOfLCIS(nums) << endl;
	cout << st.findLengthOfLCTIS1(nums) << endl;
	return 0;
}