#include <iostream>
#include <vector>
using namespace std;

//���������ڵ����ң����������������������ֵ

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		vector<int> dp(nums.size(), 0);  //dp[i]��ʾ���ǵ�i�����ڣ���������Ǯ�����ֵ
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);  //dp[i]�����ֵ�����������һ������i�ң���ôdp[i]=dp[i-2]+nums[i]�����ǲ�����i�ң���ôdp[i]=dp[i-1]
		}
		return dp[nums.size() - 1];
	}

	//�ڶ�����������û�����������ڶ������������о���İ��������û����һ��
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