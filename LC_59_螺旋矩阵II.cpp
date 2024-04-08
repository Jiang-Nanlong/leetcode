#include <iostream>
#include <vector>
using namespace std;

/*
* 给一个正整数 n ，生成一个包含 1 到 n方的所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵
*/
//这个题就是考察代码，不考算法。
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int i = 0, j = 0, count = 0;
		for (int k = 0; k <= n / 2; k++) {
			i = k;
			j = k;
			for (; j < n - k; j++)
				res[i][j] = ++count;
			for (++i, --j; i < n - k; i++)
				res[i][j] = ++count;
			for (--j, --i; j >= k; j--)
				res[i][j] = ++count;
			for (--i, ++j; i >= k + 1; i--)
				res[i][j] = ++count;
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<vector<int>> res = st.generateMatrix(4);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
