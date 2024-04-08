#include<iostream>
#include <vector>
using namespace std;

//这是LeetCode 70 爬楼梯的进阶版，原题是一步可以走1或2个台阶，这里改为一步可以走1个台阶，2个台阶，3个台阶。。。直到m个台阶，
//问有多少种不同的方法爬到楼顶
//这一看就是一个完全背包问题，而且还是一个求排列的问题
class Solution {
public:
	int climbStairs(int n, int m) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i >= j)
					dp[i] += dp[i - j];
			}
		}
		return dp[n];
	}
};

int main() {
	Solution st;
	int n = 3, m = 2;  //m=2时变成原题
	cout << st.climbStairs(n, m) << endl;
	return 0;
}
