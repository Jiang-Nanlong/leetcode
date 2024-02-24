#include <iostream>
#include <vector>
using namespace std;

//����һ����������ƽ�����ĺͱ�ʾ����������С��ƽ�����ĸ���
//����ƽ���ĵط�֮�⣬����Ķ���LeetCode 322 ��Ǯ�һ�һ��
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i * i <= n; i++) {
			for (int j = i * i; j <= n; j++)
				dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
		return dp[n];
	}
};

int main() {
	Solution st;
	cout << st.numSquares(12) << endl;
	return 0;
}