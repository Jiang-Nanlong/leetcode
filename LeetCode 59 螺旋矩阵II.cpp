#include <iostream>
#include <vector>
using namespace std;

/*
* ��һ�������� n ������һ������ 1 �� n��������Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ���
*/
//�������ǿ�����룬�����㷨��
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