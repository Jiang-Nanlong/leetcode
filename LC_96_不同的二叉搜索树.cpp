#include <iostream>
#include <vector>
using namespace std;

//������dp�����Լ��±�ĺ���ȽϺ��룬���ǵ��ƹ�ʽ��Ū�����˴�������¼��pdf��������⣬��Ҫ�Լ���������Ƚ�����
//û�뵽���Ĵ������ô���

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}

	//�ڶ�����������û�����������Ҳ������ƹ�ϵ����ûע�⵽����������״�ϵ���ϵ
	int numTrees1(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};

int main() {
	Solution st;
	cout << st.numTrees(3) << endl;
	return 0;
}