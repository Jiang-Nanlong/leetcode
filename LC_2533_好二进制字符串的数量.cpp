#include <iostream>
#include <vector>
using namespace std;

//�����ĸ����� minLength��maxLength��oneGroup �� zeroGroup ��
//
//�ö������ַ�����������������
//
//�ַ����ĳ�����[minLength, maxLength] ֮�䡣
//ÿ������ 1 �ĸ����� oneGroup ��������
//�����ڶ������ַ��� 00110111100 �У�ÿ������ 1 �ĸ����ֱ���[2, 4] ��
//ÿ������ 0 �ĸ����� zeroGroup ��������
//�����ڶ������ַ��� 00110111100 �У�ÿ������ 0 �ĸ����ֱ���[2, 1, 2] ��
//�뷵�� �� �������ַ����ĸ������𰸿��ܴܺ��뷵�ض� 109 + 7 ȡ�� ��Ľ����
//
//ע�⣺0 ���Ա���Ϊ���������ֵı�����

// ������LeetCode 2466 ͳ�ƹ�����ַ����ķ����� һģһ��

class Solution {
public:
	int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
		vector<int> dp(maxLength + 1);
		dp[0] = 1;
		int mod = 1e9 + 7;
		for (int i = 1; i <= maxLength; ++i) {
			if (i >= oneGroup) {
				dp[i] = (dp[i] + dp[i - oneGroup]) % mod;
			}
			if (i >= zeroGroup) {
				dp[i] = (dp[i] + dp[i - zeroGroup]) % mod;
			}
		}
		int res = 0;
		for (int i = minLength; i <= maxLength; i++) {
			res = (res + dp[i]) % mod;
		}
		return res;
	}
};

int main() {
	Solution st;
	int minLength = 2, maxLength = 3, oneGroup = 1, zeroGroup = 2;
	cout << st.goodBinaryStrings(minLength, maxLength, oneGroup, zeroGroup) << endl;
	return 0;
}