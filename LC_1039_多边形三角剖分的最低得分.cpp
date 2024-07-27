#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
	int minScoreTriangulation(vector<int>& values) {
		int n = values.size();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		function<int(int, int)> dfs = [&](int i, int j) {
			if (i + 1 == j)
				return 0;
			if (dp[i][j] != -1)
				return dp[i][j];
			int res = INT_MAX;
			for (int k = i + 1; k < j; k++) {
				res = min(res, dfs(i, k) + dfs(k, j) +
					values[i] * values[j] * values[k]);
			}
			dp[i][j] = res;
			return res;
			};

		return dfs(0, n - 1);
	}

	int minScoreTriangulation1(vector<int>& values) {
		int n = values.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n; i >= 0; i--) {
			for (int j = i + 2; j < n; j++) {
				dp[i][j] = INT_MAX;
				for (int k = i + 1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
				}
			}
		}

		return dp[0][n - 1];
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1, 3, 1, 4, 1, 5 };
	cout << st.minScoreTriangulation(nums) << endl;
	cout << st.minScoreTriangulation1(nums) << endl;

	return 0;
}