#include <iostream>
#include <vector>
using namespace std;

//����⻹�ǱȽϼ򵥵ģ�dp�����Ǹ���ά���飬dp[i][j]��ʾ�����i�е�j��λ�õ�·���������ڵ�һ�ŵĽڵ�ֻ������ߵĽڵ��ȥ����ֻ��һ��·��
//��һ�еĽڵ�ֻ�����ϱߵĽڵ�����������Ľڵ���ȿ��Դ��ϱ߹�����Ҳ���Դ���߹�����
//���Ե�����dp����͵��ƹ�ʽ���������ˡ�

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {  //��Ȼ����Ķ���forѭ���е��ж�����Ҳ���Բ���д����ô���ӣ�Ҳ���԰ѵ�һ�к͵�һ�е����ó������ֱ���һ��forѭ�����
				if (i == 0 && j == 0)
					continue;
				else if (i == 0) {
					dp[i][j] = dp[i][j - 1];
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
				}
			}
		}
		return dp[m - 1][n - 1];
	}

	//�ڶ�����
	int uniquePaths1(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
			dp[i][0] = 1;
		for (int i = 0; i < n; i++)
			dp[0][i] = 1;

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

		return dp[m - 1][n - 1];
	}

	//���ʹ��һά�����Ż����Ҷ��ˣ���ά����ĵ��ƹ�ʽ��dp[i][j] = dp[i - 1][j] + dp[i][j - 1]����ǰ�ڵ�����ߺ��ϱ��Ƴ�
	//ʹ�ù��������Ժ�ǰλ�õ�Ԫ����ʵ�͵������Ϸ���Ԫ�ص�ֵ�����Ե��ƹ�ʽ�ͱ��dp[i]+=dp[i-1];
	int uniquePaths2(int m, int n) {
		vector<int> dp(n,1);

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)  //ÿ��Ԫ�ض�����ǰһ��ֵ�Ƶ��������Ե�0���͵���ֵ����Ͷ�ά�����ʼ�ĳ�ʼ����һ����
				dp[j] += dp[j - 1];

		return dp[n - 1];
	}

	int uniquePaths3(int m, int n) {
		int dp[n];
		for (int i = 0; i < n; i++)
			dp[i] = 1;

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				dp[j] += dp[j - 1];

		return dp[n-1];
	}
	
};

//������������¼pdf�ϻ����Ż��棬ֻ��Ҫһ��һά������У������ҿ���̫��
int main() {
	Solution st;
	cout << st.uniquePaths(3, 7) << endl;
	return 0;
}