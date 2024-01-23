#include <iostream>
#include <vector>
#include <string>
using namespace std;

//��˵�е�N�ʺ�����
//��ʵ�����ֻҪ�������νṹ���������Ļ������˼·һ��

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> chessboard(n, string(n, '.')); //����ط�һ��ʼ��Ҫ���˳�ʼ������
		Helper(n, 0, chessboard, res);
		return res;
	}
	void Helper(int n, int row, vector<string>& chessboard, vector<vector<string>>& res) {
		if (row == n) {
			res.push_back(chessboard);
			return;
		}
		for (int col = 0; col < n; col++) {
			if (isvalid(row, col, chessboard, n)) {
				chessboard[row][col] = 'Q';
				Helper(n, row + 1, chessboard, res);
				chessboard[row][col] = '.';
			}
		}
	}
	bool isvalid(int row, int col, vector<string>& chessboard, int n) {
		for (int i = 0; i < row; i++) {
			if (chessboard[i][col] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (chessboard[i][j] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
			if (chessboard[i][j] == 'Q')
				return false;
		}
		return true;
	}
};

void main() {
	Solution st;
	vector<vector<string>> res = st.solveNQueens(4);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << endl;
		cout << endl;
	}
}