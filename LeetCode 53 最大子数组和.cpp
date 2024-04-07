#include <iostream>
#include <vector>
using namespace std;

//给定一个数组，找出数组中具有最大和的连续子数组
//局部最优：当连续和为负数时，就从下一个数重新开始，因为负数只会拖累连续和
//局部最优退出全局最优，所以可以使用贪心
//还是不熟练，找不到问题的关键，一下子没想出来，还是看了题解才想出来。

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int result = INT_MIN;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			count += nums[i];
			if (count > result)  //这个地方应该先保存结果，然后再判断count是不是<=0，因为nums数组中可能全是负数，
				//如果这两个判断写反了，就会先置为0，然后再保存结果，然后就出错了
				result = count;

			if (count <= 0) {
				count = 0;
			}

		}
		return result;
	}

	//这个题还可以用动态规划来做，现在再来做这题就感觉很简单了
	int maxSubArray1(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int res = dp[0];

		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			if (dp[i] > res) res = dp[i];
		}
		return res;
	}

	//还可以对dp数组进行优化，这里可以直接用nums数组来当dp数组
	int maxSubArray2(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			nums[i] = max(nums[i - 1] + nums[i], nums[i]);
			if (nums[i] > res) res = nums[i];
		}
		return res;
	}

	//贪心算法
	int maxSubArray3(vector<int>& nums) {
		int maxsum = INT_MIN, sum = 0;
		for (auto& i : nums) {
			maxsum = max(maxsum, sum + i);
			if (sum + i < 0) {
				sum = 0;
			}
			else {
				sum += i;
			}
		}
		return maxsum;
	}

	//动态规划
	int maxSubArray4(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			res = max(res, dp[i]);
		}
		return res;
	}
};

void main() {
	Solution st;
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	cout << st.maxSubArray(nums) << endl;
	cout << st.maxSubArray1(nums) << endl;
	cout << st.maxSubArray2(nums) << endl;
}