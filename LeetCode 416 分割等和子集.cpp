#include <iostream>
#include <vector>
using namespace std;

//����һ����������ɵķǿ����飬�жϸ������Ƿ���Էֳ������֣��������ֵ�Ԫ�غ���ͬ��
//һ��ʼ���벻�����������ô�ͱ���������ϵ������������Ƶ��֪��������ָ��Ԫ�غ���ͬ�������֣�����Ϳ��Գ���Ϊ��������������sum/2��С�ı�����
//������ת�����˱������⣬����ÿ��Ԫ��ֻ����һ�Σ����Ի���01��������������������ͼ�ֵ����������ͬһ������
//������dp[target]==target��˵��ǡ�ÿ���װ������Ϊtarget�ı���
//�����1 <= nums.length <= 200��1 <= nums[i] <= 100
class Solution {
public:
	bool canPartition(vector<int>& nums) {
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
};

int main() {
	Solution st;
	vector<int> nums{ 1,5,11,5 };
	cout << boolalpha << st.canPartition(nums) << noboolalpha << endl;
	return 0;
}
