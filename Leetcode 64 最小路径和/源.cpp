/**
ͬ62 63������������Ͻǵ������½ǣ������ÿһ����һ�����֣��ڼ�ֻ�����һ����£������ֺ���С�Ƕ���
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> path;
		//���²����˸����ķ�ʽ>>
		//dp[0][0] = grid[0][0];
		//for (int i = 0; i < m; i++) {
		//	for (int j = 0; j < n; j++) {
		//		if (i > 0 && j > 0) {
		//			//��һ���޸�>>
		//			/*if (dp[i - 1][j] >= dp[i][j - 1])
		//				dp[i][j] = dp[i][j - 1] + grid[i][j];
		//			else
		//				dp[i][j] = dp[i - 1][j] + grid[i][j];*/
		//			//��һ���޸�<<
		//			dp[i][j] = min(dp[i][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
		//		}
		//		else if (i > 0) {
		//			dp[i][j] = dp[i - 1][j] + grid[i][j];
		//		}
		//		else if (j > 0) {
		//			dp[i][j] = dp[i][j - 1] + grid[i][j];
		//		}
		//	}
		//}
		//���²����˸����ķ�ʽ<<
		// 
		//Ȼ���˹�ˮ��Ҷд�Ĵ��뷢�ֿ����޸ĳɸ����ķ�ʽ����Ϊ����ⲻͬ��ǰ������Ҫ����·���Ŀ����ԣ�����������ǿ���·�����ȣ�
		//�����Ļ��Ϳ��԰Ѳ��ɴ��·�����ó�INT_MAX
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(i == 0 && j == 0)
					dp[0][0] = grid[0][0];
				else {
					int top = i - 1 >= 0 ? dp[i - 1][j] + grid[i][j] : INT_MAX;  //���i���ǵ�0�еĻ���˵��������һ������ͨ��������һ�й�����������޷����ϱ߹���������Ϊ�����
					int left = j - 1 >= 0 ? dp[i][j - 1] + grid[i][j] : INT_MAX;
					dp[i][j] = min(top, left);
				}
			}
		}
		//�������޸ĵĻ����Ͼ��ܰ�֮ǰ��·�������������ˣ�����ǰ�֮ǰ�����������д��ʱ����֪������������������ˣ�����Ҳû��֪���ü�¼��һ��·����
		return dp[m - 1][n - 1];
	}
};
//�Լ����������ˣ�̫ţ����

int main() {
	vector<vector<int>> grid = { {1,2,3},{4,5,6} };
	Solution s = Solution();
	int minSum = s.minPathSum(grid);
	cout << minSum << endl;
	return 0;
}
