#include <iostream>
#include <vector>
using namespace std;

//这个题还是比较简单的，dp数组是个二维数组，dp[i][j]表示到达第i行第j个位置的路径数，对于第一排的节点只能又左边的节点过去，即只有一条路径
//第一列的节点只能由上边的节点过来，其他的节点则既可以从上边过来，也可以从左边过来。
//所以到这里dp数组和递推公式都很清晰了。

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {  //当然这里的二重for循环中的判断条件也可以不用写的这么复杂，也可以把第一行和第一列单独拿出来，分别用一个for循环完成
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

	//第二次做
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

	//这个使用一维数组优化的我懂了，二维数组的递推公式是dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，当前节点由左边和上边推出
	//使用滚动数组以后当前位置的元素其实就等于它上方的元素的值，所以递推公式就变成dp[i]+=dp[i-1];
	int uniquePaths2(int m, int n) {
		vector<int> dp(n,1);

		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)  //每个元素都由它前一个值推导出，所以第0个就得有值，这和二维数组最开始的初始化是一样的
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

//这个题代码随想录pdf上还有优化版，只需要一个一维数组就行，但是我看不太懂
int main() {
	Solution st;
	cout << st.uniquePaths(3, 7) << endl;
	return 0;
}