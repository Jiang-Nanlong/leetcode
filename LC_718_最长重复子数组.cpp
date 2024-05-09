#include <iostream>
#include <vector>
using namespace std;

//��Ŀ�����������飬������������������ͬ���ַ���������ȡ�

//dp[i][j]��ʾnums1����i-1Ϊ��β��nums2����j-1Ϊ��β���ַ�������������������ĳ��ȡ�Ϊʲôdp[i][j]Ҫ��ʾi-1��j-1λ�������Ǳ�ʾiλ��jλ�أ���Ϊ�ڳ�ʼ����ʱ�����Ҳ�����ж�nums1�ĵ�һ���ַ���nums2�е��ַ������һ����ͬ��
//nums2�еĵ�һ���ַ���nums1�е��ַ�Ҳ������һ���������Ļ����ڳ�ʼ��dp����ʱ�͵ý����жϣ��ͱȽφ��¡�
//�����dp[i][j]��ʾ��i-1Ϊ��β��j-1Ϊ��β���ַ����Ļ�����ͬ���ʼ��Ϊ0�����ˣ���ߵĶ������Լ����ݵ��ƹ�ʽ�Լ��Ƶ�������

//�������ѵ���dp����Ĵ�����dp[i][j]����˼���Լ���ʼ�������⡣

class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
		int res = 0;
		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = 1; j <= nums2.size(); j++) {
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;

				if (dp[i][j] > res) //��󳤶Ȳ�һ��������dp��������½�
					res = dp[i][j];
			}
		}
		return res;
	}

	//�±ߵĴ�����dp[i][j]��ʾ��iΪ��β����jΪ��β���ַ�������ظ�������ĳ���
	//�ڳ�ʼ����ʱ���е��鷳����ʵҲ���ã����ֿ������������һЩ��
	int findLength1(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
		int res = 0;
		for (int i = 0; i < nums2.size(); i++) if (nums1[0] == nums2[i]) dp[0][i] = 1;
		for (int i = 0; i < nums1.size(); i++) if (nums1[i] == nums2[0]) dp[i][0] = 1;

		for (int i = 0; i < nums1.size(); i++) {  //�����i��jȷʵ�ǲ��ܴ�1��ʼ����Ϊ�����������1����ֻ�г�ʼ����ʱ���е���������ͬ�ģ����Ǻ�ߵ�ȫ��ͬ�����i��j��1��ʼ�Ļ��ͻ�������Щ��ͬ�����֣���󷵻�0
			for (int j = 0; j < nums2.size(); j++) {
				if (nums1[i] == nums2[j] && i > 0 && j > 0)
					dp[i][j] = dp[i - 1][j - 1] + 1;

				if (dp[i][j] > res)
					res = dp[i][j];
			}
		}
		return res;
	}

	//�ڶ�����
	//��ʼ��ʱ��һ��ͷ��û�У���������һ����Ƶ�����˸���ͷ�ͻ�Ȼ����
	//�������ѵ���Ҫ��dp����ĺ�������
	//dp[i][j]��ʾnums1����iΪ��β���������nums2����jΪ��β���������ظ�������ĳ���
	int findLength2(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
		int res = 0;

		for (int i = 0; i < nums2.size(); i++) {  //��ʼ��dp����
			if (nums1[0] == nums2[i])
				dp[0][i] = 1;
			res = max(res, dp[0][i]); //�п��ܲ���������ֻ��һ��Ԫ����ͬ���ҳ����ڳ�ʼ�������ʱ��
		}
		for (int i = 0; i < nums1.size(); i++) { //ͬ��
			if (nums1[i] == nums2[0])
				dp[i][0] = 1;
			res = max(res, dp[i][0]);
		}

		for (int i = 1; i < nums1.size(); i++) {
			for (int j = 1; j < nums2.size(); j++) {
				if (nums1[i] == nums2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
		return res;
	}

	//pdf�ϵ�д�������Ա����鷳�ĳ�ʼ����ֱ�����һ�ж����
	//dp[i][j]��ʾnums1����i-1Ϊ��β���������nums2����j-1Ϊ��β���������ظ�������ĳ���
	//�����Ͳ��ó�ʼ�������һ�к����ϱ�һ���ˣ���Ϊ������û������
	int findLength3(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
		int res = 0;
		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = 1; j <= nums2.size(); j++) {
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
		return res;
	}

	//����Ҳ����ʹ��һά����
	int findLength4(vector<int>& nums1, vector<int>& nums2) {
		vector<int> dp(nums2.size() + 1, 0);
		int res = 0;

		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = nums2.size(); j > 0; j--) {
				//���������ǵ����������Ϊnums1[i-1]��nums2[j-1]��ȵĻ������nums1[i]��nums2[j]����ȣ�
				// ����Ϳ���ֱ�Ӵ�ǰһ�������1���������Ļ���ǰһ�������ֵ���ܾͲ�����
				if (nums1[i - 1] == nums2[j - 1])
					dp[j] = dp[j - 1] + 1;
				else
					dp[j] = 0;  //ע��������������Ҫ��Ϊ0
				res = max(res, dp[j]);
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums1{ 1,2,3,2,1 }, nums2{ 3,2,1,4,7 };
	cout << st.findLength(nums1, nums2) << endl;
	cout << st.findLength1(nums1, nums2) << endl;
	return 0;
}