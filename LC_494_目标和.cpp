#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//����һ�������������һ��target���������е�����ǰ��+ -�ţ�������͵���target���������������
//���ǿ������û��������ˣ�������ȫû�����Ǳ�������
// 
//���ݣ����ݷ�д����ͦ��
class Solution {
public:
	int count = 0;
	int findTargetSumWays(vector<int>& nums, int target) {
		backtrack(nums, target, 0, 0);
		return count;
	}

	void backtrack(vector<int>& nums, int target, int startindex, int sum) {
		if (startindex == nums.size()) {
			if (sum == target)
				count++;
		}
		else {
			backtrack(nums, target, startindex + 1, sum + nums[startindex]);
			backtrack(nums, target, startindex + 1, sum - nums[startindex]);
		}
	}

	//��̬�滮������е���
	//left���-right���=target  left���+right���=sum������left=(sum+target)/2
	//Ҳ�������������Ҽ������ĺ͵���left���Ϳ���ת��Ϊ01���������ˣ����һ��������������ÿ��������ŵ����⡣
	int findTargetSumWays1(vector<int>& nums, int target) {
		int sum = 0;
		for (int& i : nums) sum += i;
		if (abs(target) > sum) return 0;
		if ((sum + target) % 2 == 1) return 0;  //���sum+target���������ͷ���0
		int bagsize = (sum + target) / 2;

		vector<int> dp(bagsize + 1, 0);
		dp[0] = 1;  //����ĳ�ʼ�������е�Ū��̫��
		for (int i = 0; i < nums.size(); i++) {
			for (int j = bagsize; j >= nums[i]; j--) {
				dp[j] += dp[j - nums[i]];  //�پ��ǵ��ƹ�ʽ���о�����¥�ݵ��Ǹ�һ����
			}
			for (int k : dp)
				cout << k << "  ";
			cout << endl;
		}
		return dp[bagsize];
	}

	int findTargetSumWays2(vector<int>& nums, int target) {  //�ö�ά����ʵ��
		int sum = 0;
		for (int& i : nums) sum += i;
		if (abs(target) > sum) return 0;
		if ((sum + target) % 2 == 1) return 0;
		int bagsize = (sum + target) / 2;

		vector<vector<int>> dp(nums.size(), vector<int>(bagsize + 1, 0));
		dp[0][0] = 1;
		if (nums[0] <= bagsize)  //�����ʼ���ĵط������⣬��ʼ���������ԣ����˱��˵Ĵ���ĵģ������ʼ���ĵط������е�Ū���壬��ӡ��dp����о���֪������е㶮��
			dp[0][nums[0]] += 1;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j <= bagsize; j++) {
				if (j < nums[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
			}
		}
		for (int i = 0; i < dp.size(); i++) {
			for (int j = 0; j < dp[0].size(); j++) {
				cout << dp[i][j] << "  ";
			}
			cout << endl;
		}
		return dp[nums.size() - 1][bagsize];
	}

	//�ڶ�����������û���뵽��ô����01����������
	int findTargetSumWays3(vector<int>& nums, int target) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if ((sum + target) % 2) return 0;
		if (abs(target) > sum) return 0;
		int left = (sum + target) / 2;
		vector<int> dp(left + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = left; j >= nums[i]; j--)
				dp[j] += dp[j - nums[i]];
		}
		return dp[left];
	}
};

//�����Ļ��ݷ����Ƚϼ򵥣���̬�滮�������ѡ�������dp�������ǿ������
//�������ѵ������ô����ɱ������⣬Ȼ����ǵ��ƹ�ʽ��
//����İ���ģ��д����
int main() {
	Solution st;
	vector<int> nums{ 1,1,1,1,1 };
	int target = 3;
	cout << st.findTargetSumWays2(nums, target) << endl;
	return 0;
}
