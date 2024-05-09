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

	//第二次做，这次大体思路是对的，递推公式也对了，但是就是把遍历顺序写成正序遍历了
	int findMaxForm1(vector<string>& strs, int m, int n) {
		//感觉这回dp数组得是二维的
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < strs.size(); i++) {
			string s = strs[i];
			int count_0 = 0, count_1 = 0;
			for (char& c : s) {
				if (c == '0') count_0++;
				else count_1++;
			}

			//经过手动验算，这里确实是应该逆序遍历。这里遍历几个物品，都是使用了相同的dp数组，就等同于之前一维的滚动数组，所以应该是逆序遍历
			//逆序遍历
			for (int j = m; j >= count_0; j--) {
				for (int k = n; k >= count_1; k--) {
					dp[j][k] = max(dp[j][k], dp[j - count_0][k - count_1] + 1);
				}
			}


			//正序遍历的，会重复前边的计算结果
			/*for (int j = count_0; j <= m; j++) {
				for (int k = count_1; k <= n; k++) {
					dp[j][k] = max(dp[j][k], dp[j - count_0][k - count_1] + 1);
				}
			}*/

			//打印dp数组
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
	cout << st.findMaxForm1(strs, m, n) << endl;
	return 0;
}