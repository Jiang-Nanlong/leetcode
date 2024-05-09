#include <iostream>
#include <vector>
using namespace std;

//�����������飬�ҳ���������ͬ����������������������Щ���ӵ��߲����ཻ���ⲻ����LeetCode 1143 ����������е��������в�һ��Ҫ������������Ĺ��������еĳ���

class Solution {
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

		for (int i = 1; i <= nums1.size(); i++) {
			for (int j = 1; j <= nums2.size(); j++) {
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[nums1.size()][nums2.size()];
	}

	//�ڶ�������������������������еķ��棬һģһ��
	int maxUncrossedLines1(vector<int>& nums1, vector<int>& nums2) {
		vector<int> dp(nums2.size() + 1, 0);

		for (int i = 1; i <= nums1.size(); i++) {
			int prev = 0;
			for (int j = 1; j <= nums2.size(); j++) {
				int temp = dp[j];
				if (nums1[i - 1] == nums2[j - 1])
					dp[j] = prev + 1;
				else
					dp[j] = max(dp[j], dp[j - 1]);
				prev = temp;
			}
		}
		return dp[nums2.size()];
	}
};

int main() {
	Solution st;
	vector<int> nums1 = { 1, 4, 2 }, nums2 = { 1, 2, 4 };
	cout << st.maxUncrossedLines(nums1, nums2) << endl;
	return 0;

}