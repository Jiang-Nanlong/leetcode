#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		auto m = triangle.size();
		vector<vector<int>> dp(m, vector<int>(m, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j <= i; j++) {
				if (i == 0 && j == 0)
					dp[0][0] = triangle[0][0];
				else {
					int left = j == 0 ? INT_MAX : dp[i - 1][j - 1];  //判断能否可以从左上方过来
					int right = j == i ? INT_MAX : dp[i - 1][j];   //判断是否可以从右上方过来
					dp[i][j] = min(left, right) + triangle[i][j];
				}
			}
		}
		int minpath = dp[m - 1][0];
		for (int i = 0; i < m; i++) {
			if (dp[m - 1][i] < minpath)
				minpath = dp[m - 1][i];
		}
		return minpath;
	}
};

int main() {
	vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
	Solution s;
	int minPath = s.minimumTotal(triangle);
	cout << minPath << endl;

	return 0;
}
//太牛逼了，第一遍就做出来了
