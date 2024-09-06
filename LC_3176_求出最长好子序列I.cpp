#include <iostream>
#include <vector>
using namespace std;

// ����һ�����������һ������k�����һ���������������k��Ԫ�ػ�����ͬ���������һ���������С�����һ����ĺ������еĳ��ȡ�

// �����Ķ�̬�滮�ⷨ��û����������ֻ�м��仯������

class Solution {
public:
	int maximumLength(vector<int>& nums, int k) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(k + 1, 1));  // dp[i][j]��ʾ��nums{i]Ϊ��β������������j��Ԫ�ػ�����ͬ��������еĳ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				int flag = nums[i] == nums[j] ? 0 : 1;  // �ж�nums[i]��nums[j]�Ƿ���ͬ
				for (int h = 0; h + flag <= k; h++) {   // ��ͷ��������Ļ�����ͬ��Ԫ�ض���
					if (dp[i][h + flag] < dp[j][h] + 1)
						// �����nums[i]Ϊ��β����h+flag�Ի�����ͬԪ�ص������е���󳤶� С�� ��nums[j]Ϊ��β����h�Ի�����ͬ��Ԫ�ص������е���󳤶�+1
						// ���޸��������nums[i]Ϊ��β����h+flag�Ի�����ͬԪ�ص������е���󳤶�
						dp[i][h + flag] = dp[j][h] + 1;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++)
				res = max(res, dp[i][j]);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,1,1,3 };
	int k = 2;
	cout << st.maximumLength(nums, k) << endl;
	return 0;
}