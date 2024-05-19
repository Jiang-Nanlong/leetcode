#include <iostream>
#include <vector>
using namespace std;

/*
* 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size(), n = matrix[0].size();
		int loop = min(m, n) / 2, i = 0, j = 0, count = 0;
		for (int k = 0; k <= loop; k++) {
			i = k;
			j = k;
			for (; j < n - k && count < m * n; j++) {
				res.push_back(matrix[i][j]);
				++count;
			}
			for (--j, ++i; i < m - k && count < m * n; i++) {
				res.push_back(matrix[i][j]);
				++count;
			}
			for (--i, --j; j >= k && count < m * n; j--) {
				res.push_back(matrix[i][j]);
				++count;
			}
			for (++j, --i; i >= k + 1 && count < m * n; i--) {
				res.push_back(matrix[i][j]);
				++count;
			}
		}
		return res;
	}

	// 第二次做
	vector<int> spiralOrder1(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<int> res(m * n);
		int count = 0;
		for (int i = 0; i <= min(m, n) / 2; i++) {
			for (int j = i; j < n - i; j++) {
				if (count < m * n)
					res[count++] = matrix[i][j];
			}
			for (int j = n - i - 1, k = i + 1; k < m - i; k++)
				if (count < m * n)
					res[count++] = matrix[k][j];
			for (int j = n - i - 2, k = m - i - 1; j >= i; j--)
				if (count < m* n)
					res[count++] = matrix[k][j];
			for (int j = i, k = m - i - 2; k > i; k--)
				if (count < m * n)
					res[count++] = matrix[k][j];
		}
		return res;
	}
};
//这个题与算法无关，纯考代码
//这里引入count是因为如果最后一层不够一圈的话，如果没有count作为约束，会有错误，既然知道了矩阵的大小，就直接弄个count控制它输出多少个数

int main() {
	Solution st;
	vector<vector<int>> matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<int> res = st.spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	vector<int> res1 = st.spiralOrder1(matrix);
	for (int i = 0; i < res1.size(); i++)
		cout << res1[i] << " ";
	cout << endl;
	exit(0);
}