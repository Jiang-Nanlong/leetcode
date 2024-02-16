#include <iostream>
#include <vector>
using namespace std;

//把一个整数拆分成多个数的和，然后返回这些数的乘积的最大值
//根据基本不等式来看，要想成绩最大，那么两个数应该一样大，或者说是差不多大，这个题放在这也是一样，几个数应该尽可能的一样大
//其实这里的dp数组和下标的含义比较好理解，就是在写递推公式时，开始想的是max(dp[i], j*dp[i-j])，看起来是没有错，但是当i=3，也就是
//第一个数时就会报错，max(dp[i], j*dp[i-j])的结果是1，实际应该是2，问题就出在了递推公式这里。
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0, dp[1] = 0, dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j <= i / 2; j++) {  //注意这里是i/2，因为前一半的结果和后一半是对称的
				dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
				//dp[i] = max(dp[i], j * dp[i - j]);   //i=3时的结果不对
			}
		}
		for (auto c : dp)
			cout << c << " ";
		return dp[n];
	}
};

int main() {
	Solution st;
	int n = 10;
	cout << st.integerBreak(n) << endl;
	return 0;
}