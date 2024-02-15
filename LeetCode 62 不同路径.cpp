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
};

//������������¼pdf�ϻ����Ż��棬ֻ��Ҫһ��һά������У������ҿ���̫��
int main() {
	Solution st;
	cout << st.uniquePaths(3, 7) << endl;
	return 0;
}