#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//����һ����������ɵķǿ����飬�жϸ������Ƿ���Էֳ������֣��������ֵ�Ԫ�غ���ͬ��
//һ��ʼ���벻�����������ô�ͱ���������ϵ������������Ƶ��֪��������ָ��Ԫ�غ���ͬ�������֣�����Ϳ��Գ���Ϊ��������������sum/2��С�ı�����
//������ת�����˱������⣬����ÿ��Ԫ��ֻ����һ�Σ����Ի���01��������������������ͼ�ֵ����������ͬһ������
//������dp[target]==target��˵��ǡ�ÿ���װ������Ϊtarget�ı���
//�����1 <= nums.length <= 200��1 <= nums[i] <= 100
class Solution {
public:
	bool canPartition(vector<int>& nums) {  //��һά������
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];

		if (sum % 2 == 1) return false;  //�������ͱ����޷��ָ��������ȵĲ��֣��ͷ���false
		int bagsize = sum / 2;

		vector<int> dp(bagsize + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = bagsize; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);  //��Ϊ����������͵��ڼ�ֵ�����Ե��ƹ�ʽҲҪ��Ӧ�ı�
			}
		}
		if (dp[bagsize] == bagsize) return true;
		return false;
	}

	bool canPartition1(vector<int>& nums) {  //�ö�ά������
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];

		if (sum % 2 == 1) return false;
		int bagsize = sum / 2;

		vector<vector<int>> dp(nums.size(), vector<int>(bagsize + 1, 0));
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j <= bagsize; j++) {
				if (j < nums[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
			}
		}
		if (dp[nums.size() - 1][bagsize] == bagsize) return true;
		return false;
	}

	//�ڶ�����
	bool canPartition2(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		sum /= 2;
		//sort(nums.begin(), nums.end());
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = sum; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		if (dp[sum] == sum)
			return true;
		return false;
	}

	// ��������
	bool canPartition3(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1)
			return false;

		sum /= 2;
		vector<int> dp(sum + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = sum; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return dp[sum] == sum;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,5,11,5 };
	cout << boolalpha << st.canPartition1(nums) << endl;
	cout << st.canPartition2(nums) << endl;
	cout << st.canPartition3(nums) << noboolalpha << endl;
	return 0;
}
