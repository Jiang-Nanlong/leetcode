#include <iostream>
#include <vector>
using namespace std;

//返回数组中最长递增子序列的长度，这个子序列不一定是连续的
//这个题的答案看的迷迷糊糊的

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 1) return 1;
		vector<int> dp(nums.size(), 1);
		int res = 0;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (dp[i] > res) res = dp[i];
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 10,9,2,5,3,7,101,18 };
	cout << st.lengthOfLIS(nums) << endl;
	return 0;
}