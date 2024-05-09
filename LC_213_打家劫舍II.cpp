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
};

int main() {
	Solution st;
	vector<int> nums{ 2,3,2 };
	cout << st.rob1(nums) << endl;
	return 0;
}