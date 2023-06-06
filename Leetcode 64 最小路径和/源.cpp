/**
同62 63，从网络的左上角到达右下角，网络的每一格都有一个数字，期间只能向右或向下，问数字和最小是多少
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
		//以下采用了更简洁的方式>>
		//dp[0][0] = grid[0][0];
		//for (int i = 0; i < m; i++) {
		//	for (int j = 0; j < n; j++) {
		//		if (i > 0 && j > 0) {
		//			//第一次修改>>
		//			/*if (dp[i - 1][j] >= dp[i][j - 1])
		//				dp[i][j] = dp[i][j - 1] + grid[i][j];
		//			else
		//				dp[i][j] = dp[i - 1][j] + grid[i][j];*/
		//			//第一次修改<<
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
		//以下采用了更简洁的方式<<
		// 
		//然后看了宫水三叶写的代码发现可以修改成跟简洁的方式，因为这个题不同于前两个题要考虑路径的可行性，这个题更多的是考虑路径长度，
		//这样的话就可以把不可达的路径设置成INT_MAX
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if(i == 0 && j == 0)
					dp[0][0] = grid[0][0];
				else {
					int top = i - 1 >= 0 ? dp[i - 1][j] + grid[i][j] : INT_MAX;  //如果i不是第0行的话，说明他的上一步可以通过他的上一行过来，否则就无法从上边过来，就设为无穷大
					int left = j - 1 >= 0 ? dp[i][j - 1] + grid[i][j] : INT_MAX;
					dp[i][j] = min(top, left);
				}
			}
		}
		//在这样修改的基础上就能把之前的路径给保存下来了，如果是按之前的三种情况的写法时，不知道是哪种情况被采纳了，所以也没法知道该记录哪一条路径。
		return dp[m - 1][n - 1];
	}
};
//自己就做出来了，太牛逼了

int main() {
	vector<vector<int>> grid = { {1,2,3},{4,5,6} };
	Solution s = Solution();
	int minSum = s.minPathSum(grid);
	cout << minSum << endl;
	return 0;
}
