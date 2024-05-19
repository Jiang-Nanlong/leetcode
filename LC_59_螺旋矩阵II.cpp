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

	// �ڶ������������һ��д�ļ�
	vector<vector<int>> generateMatrix1(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int count = 1;
		for (int i = 0; i <= n / 2; i++) {
			for (int j = i; j < n - i; j++) {
				res[i][j] = count;
				count++;
			}
			for (int j = n - i - 1, k = i + 1; k < n - i; k++) {
				res[k][j] = count;
				count++;
			}
			for (int k = n - i - 1, j = n - i - 2; j >= i; j--) {
				res[k][j] = count;
				count++;
			}
			for (int j = i, k = n - i - 2; k > i; k--) {
				res[k][j] = count;
				count++;
			}
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

	vector<vector<int>> res1 = st.generateMatrix1(3);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[0].size(); j++) {
			cout << res1[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}