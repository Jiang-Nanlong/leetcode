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
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,3,1 };
	cout << st.rob(nums) << endl;
	return 0;
}