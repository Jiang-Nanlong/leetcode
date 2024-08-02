#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ʹ��9�����֣�һ�������������Σ����ܻ��м��ֲ�ͬ�Ľ��������һ���������У����ܹ��ж����ִ��ֵĽ��
// ����222��������aaa,ab,ba,c�� 2,3,4,5,6,8�⼸�ְ�����������ĸ��7,9���ĸ���ĸ

class Solution {
public:
	int countTexts(string pressedKeys) {
		int n = pressedKeys.size();
		int nn = max(3, n);  // ��ʱ��n��С��3��Ȼ���±ߵĳ�ʼ���ͻᱨԽ�����
		int mod = 1e9 + 7;
		vector<int> dp1(nn + 1), dp2(nn + 1);
		dp1[0] = dp2[0] = 1;
		dp1[1] = dp2[1] = 1;
		dp1[2] = dp2[2] = 2;
		dp1[3] = dp2[3] = 4;

		for (int i = 4; i <= n; ++i) {
			dp1[i] = (1LL * dp1[i - 1] + dp1[i - 2] + dp1[i - 3]) % mod;
			dp2[i] = (1LL * dp2[i - 1] + dp2[i - 2] + dp2[i - 3] + dp2[i - 4]) % mod;
		}

		int i = 0, j = 0;
		int res = 1;
		while (i < n) {
			char num = pressedKeys[i];
			int count = 1;
			while (++j < n && pressedKeys[j] == num)  // ͳ��������ͬ�ַ��ĸ���
				++count;

			if (num == '7' || num == '9') {
				res = 1LL * res * dp2[count] % mod;
			}
			else {
				res = 1LL * res * dp1[count] % mod;
			}
			i = j;
		}
		return res;
	}
};

int main() {
	Solution st;
	string s("444479999555588866");
	cout << st.countTexts(s) << endl;
	return 0;
}