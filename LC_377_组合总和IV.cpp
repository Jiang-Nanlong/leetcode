#include <iostream>
#include <vector>
using namespace std;

//����һ���������飬��һ��target�����������ҳ������ճ�target�����ֿ����ظ�ʹ�á���һ������һ����ȫ����������
//������Ŀ��һ��Ҫ����Ŀ���ݱ�֤�𰸷��� 32 λ������Χ
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int j = 0; j <= target; j++) {
			for (int i = 0; i < nums.size(); i++) {
				if (j >= nums[i] && (long long)dp[j] + dp[j - nums[i]] < INT_MAX)  //����жϺ����������Ϊ�����������г���32λ������Χ������
					//����Ŀ��Ҫ��𰸶�����32λ������Χ�����Գ���32λ֤�鷶Χ������ֱ�Ӳ��ÿ�����
					dp[j] += dp[j - nums[i]];
			}
		}
		return dp[target];
	}

	//�ڶ�����������һ����ȫ���������е��⣬�ȱ�������Ʒ���У����Ǿ����еĲ�������������
	int combinationSum41(vector<int>& nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int j = 0; j <= target; j++) {
			for (int i = 0; i < nums.size(); i++) {
				if (j >= nums[i] && (long long)dp[j] + dp[j - nums[i]] < INT_MAX) {
					dp[j] += dp[j - nums[i]];
				}
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