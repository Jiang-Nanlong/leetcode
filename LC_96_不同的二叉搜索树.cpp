#include <iostream>
#include <vector>
using namespace std;

//这个题的dp数组以及下标的含义比较好想，但是递推公式难弄，看了代码随想录的pdf才慢慢理解，想要自己推算出来比较困难
//没想到最后的代码会这么简短

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}

	//第二遍做，还是没有做出来，找不出递推关系，更没注意到左右子树形状上的联系
	int numTrees1(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};

int main() {
	Solution st;
	cout << st.numTrees(3) << endl;
	return 0;
}