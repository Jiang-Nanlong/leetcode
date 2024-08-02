#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 使用9键打字，一个键连续按几次，可能会有几种不同的结果，输入一个按键序列，问总共有多少种打字的结果
// 比如222，可以是aaa,ab,ba,c。 2,3,4,5,6,8这几种按键有三个字母，7,9有四个字母

class Solution {
public:
	int countTexts(string pressedKeys) {
		int n = pressedKeys.size();
		int nn = max(3, n);  // 有时候n会小于3，然后下边的初始化就会报越界错误
		int mod = 1e9 + 7;
		vector<int> dp1(nn + 1), dp2(nn + 1);
		dp1[0] = dp2[0] = 1;
		dp1[1] = dp2[1] = 1;
		dp1[2] = dp2[2] = 2;
		dp1[3] = dp2[3] = 4;

		for (int i = 4; i <= n; ++i) {
			dp1[i] = (1LL * dp1[i - 1] + dp1[i - 2] + dp1[i - 3]) % mod;
			dp2[i] = (1LL * dp2[i - 1] + dp2[i - 2] + dp2[i - 3] + dp2[i - 4]) % mod;
		}

		int i = 0, j = 0;
		int res = 1;
		while (i < n) {
			char num = pressedKeys[i];
			int count = 1;
			while (++j < n && pressedKeys[j] == num)  // 统计连续相同字符的个数
				++count;

			if (num == '7' || num == '9') {
				res = 1LL * res * dp2[count] % mod;
			}
			else {
				res = 1LL * res * dp1[count] % mod;
			}
			i = j;
		}
		return res;
	}
};

int main() {
	Solution st;
	string s("444479999555588866");
	cout << st.countTexts(s) << endl;
	return 0;
}