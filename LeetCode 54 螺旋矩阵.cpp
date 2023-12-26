#include <iostream>
#include <vector>
using namespace std;

/*
* ����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
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
};
//��������㷨�޹أ���������
//��������count����Ϊ������һ�㲻��һȦ�Ļ������û��count��ΪԼ�������д��󣬼�Ȼ֪���˾���Ĵ�С����ֱ��Ū��count������������ٸ���

int main() {
	Solution st;
	vector<vector<int>> matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<int> res = st.spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}