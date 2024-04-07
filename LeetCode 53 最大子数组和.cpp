#include <iostream>
#include <vector>
using namespace std;

//����һ�����飬�ҳ������о������͵�����������
//�ֲ����ţ���������Ϊ����ʱ���ʹ���һ�������¿�ʼ����Ϊ����ֻ������������
//�ֲ������˳�ȫ�����ţ����Կ���ʹ��̰��
//���ǲ��������Ҳ�������Ĺؼ���һ����û����������ǿ��������������

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int result = INT_MIN;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			count += nums[i];
			if (count > result)  //����ط�Ӧ���ȱ�������Ȼ�����ж�count�ǲ���<=0����Ϊnums�����п���ȫ�Ǹ�����
				//����������ж�д���ˣ��ͻ�����Ϊ0��Ȼ���ٱ�������Ȼ��ͳ�����
				result = count;

			if (count <= 0) {
				count = 0;
			}

		}
		return result;
	}

	//����⻹�����ö�̬�滮��������������������͸о��ܼ���
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

	//�����Զ�dp��������Ż����������ֱ����nums��������dp����
	int maxSubArray2(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			nums[i] = max(nums[i - 1] + nums[i], nums[i]);
			if (nums[i] > res) res = nums[i];
		}
		return res;
	}

	//̰���㷨
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

	//��̬�滮
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