#include <iostream>
#include <vector>
using namespace std;

//这个题不用动态规划也能做，主要是用来熟悉动态规划的五个步骤
//1、确认dp数组以及下标的含义
//2、确定递推公式
//3、dp数组如何初始化
//4、确定遍历顺序
//5、距离推导dp数组

class Solution {
public:
	int fib(int n) {
		if (n <= 1) return n;
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}

	//其实这里不用声明n个大小的数组就行，可以看到每个位置的斐波那契数只与它之前的两个数有关
	int fib1(int n) {
		if (n <= 1) return n;
		int dp[2];
		dp[0] = 0, dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			int sum = dp[0] + dp[1];
			dp[0] = dp[1];
			dp[1] = sum;
		}
		return dp[1];
	}
};

int main() {
	Solution st;
	int n = 4;
	cout << st.fib(4) << endl;
	cout << st.fib1(4) << endl;
	return 0;
}