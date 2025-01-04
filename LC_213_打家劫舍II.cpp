#include <iostream>
#include <vector>
using namespace std;

//���Ǹ���ҽ�������һ������������ķ��ӻ����ɻ�
//���Ծͷ������������һ�־���ͷβԪ�ض���ȡ���ڶ��־��ǲ�ȡβԪ�أ������־��ǲ�ȡ��Ԫ��
//�����뵽Ҳ���ɣ���Ԫ�غ�βԪ�ز���ͬʱ���ǣ�ÿ�����ѭ��һ�飬һ������

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int result1 = robRange(nums, 0, nums.size() - 2);
		int result2 = robRange(nums, 1, nums.size() - 1);
		return max(result1, result2);
	}
	int robRange(vector<int>& nums, int start, int end) {
		if (start == end) return nums[start];
		vector<int> dp(nums.size());
		dp[start] = nums[start];
		dp[start + 1] = max(nums[start], nums[start + 1]);
		for (int i = start + 2; i <= end; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[end];
	}

	//�ڶ����������Ƿ����������ȡ��һ���Ͳ���ȡ���һ����ȡ���һ���Ͳ���ȡ��һ��
	int rob1(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		int value1 = robHelper(nums, 0, nums.size() - 1);
		int value2 = robHelper(nums, 1, nums.size());
		return max(value1, value2);
	}

	int robHelper(vector<int>& nums, int begin, int end) { // ����ҿ�
		if (end - begin == 1)
			return nums[begin];
		vector<int> dp(nums.size(), 0);
		dp[begin] = nums[begin];
		dp[begin + 1] = max(nums[begin], nums[begin + 1]);
		for (int i = begin + 2; i < end; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[end - 1];
	}

// ͵��һ������Ͳ���͵���һ������֮��Ȼ�����Էֿ�д��һ���Ǵ�0~n-1��һ���Ǵ�1~n
	int rob3(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		int n = nums.size();
		vector<int> dp1(n - 1, 0);
		vector<int> dp2(n, 0);

		dp1[0] = nums[0];
		dp1[1] = max(nums[0], nums[1]);
		for (int i = 2; i < n - 1; i++) {
			dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
		}

		dp2[1] = nums[1];
		dp2[2] = max(nums[1], nums[2]);
		for (int i = 3; i < n; i++) {
			dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
		}
		return max(dp1.back(), dp2.back());
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,3,2 };
	cout << st.rob1(nums) << endl;
	return 0;
}