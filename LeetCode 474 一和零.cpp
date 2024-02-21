#include <iostream>
#include <vector>
using namespace std;

//给定一个字符数组，数组中的每一个元素都是一个二进制串，最后返回一个数组的子集，子集中的元素中的0的个数不超过m，1的个数不超过n

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (string& s : strs) {   //这里相当于遍历物品
			int zeroNum = 0, oneNum = 0;
			for (char& c : s) {
				if (c == '0') zeroNum++;
				else oneNum++;
			}

			for (int i = m; i >= zeroNum; i--) {
				for (int j = n; j >= oneNum; j--) {
					dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
				}
			}

			for (int i = 0; i <= m; i++) {
				for (int j = 0; j <= n; j++) {
					cout << dp[i][j] << "   ";
				}
				cout << endl;
			}
			cout << "--------------------" << endl;
		}
		return dp[m][n];
	}
};

int main() {
	Solution st;
	vector<string> strs{ "10", "0001", "111001", "1", "0" };
	int m = 5, n = 3;
	cout << st.findMaxForm(strs, m, n) << endl;
	return 0;
}