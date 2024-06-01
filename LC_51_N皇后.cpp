#include <iostream>
#include <vector>
#include <string>
using namespace std;

//传说中的N皇后问题
//其实这个题只要画出树形结构，跟以往的回溯题的思路一样

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> chessboard(n, string(n, '.')); //这个地方一开始不要忘了初始化棋盘
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

	//第二次做，感觉整体思路没问题，不过就是写的磕磕巴巴，没有信心
	vector<vector<string>> res;

	vector<vector<string>> solveNQueens1(int n) {
		string s(n, '.');
		vector<string> chessboard(n, s);
		backtracking(chessboard, n, 0);
		return res;
	}

	void backtracking(vector<string>& chessboard, int n, int row) {
		if (row == n) {
			res.push_back(chessboard);
			return;
		}

		for (int col = 0; col < n; col++) {
			if (isValid1(row, col, chessboard, n)) {
				chessboard[row][col] = 'Q';
				backtracking(chessboard, n, row + 1);
				chessboard[row][col] = '.';
			}
		}
	}
	bool isValid1(int row, int col, vector<string>& chessboard, int n) {
		for (int i = 0; i < n; i++)
			if (chessboard[i][col] == 'Q')
				return false;

		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
			if (chessboard[i][j] == 'Q')
				return false;

		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
			if (chessboard[i][j] == 'Q')
				return false;

		return true;
	}

	//从棋盘下边往上遍历，用n表示当前所在的行
	vector<vector<string>> solveNQueens2(int n) {
		string s(n, '.');
		vector<string> chessboard(n, s);
		res.clear();
		backtracking1(chessboard, n - 1);
		return res;
	}

	void backtracking1(vector<string>& chessboard, int n) {
		if (n == -1) {
			res.push_back(chessboard);
			return;
		}

		for (int col = 0; col < chessboard.size(); col++) {
			if (isValid2(chessboard, n, col)) {
				chessboard[n][col] = 'Q';
				backtracking1(chessboard, n - 1);
				chessboard[n][col] = '.';
			}
		}
	}
	bool isValid2(vector<string>& chessboard, int row, int col) {
		for (int i = row + 1; i < chessboard.size(); i++)
			if (chessboard[i][col] == 'Q')
				return false;

		for (int i = row + 1, j = col - 1; i < chessboard.size() && j >= 0; i++, j--)
			if (chessboard[i][j] == 'Q')
				return false;

		for (int i = row + 1, j = col + 1; i < chessboard.size() && j < chessboard.size(); i++, j++)
			if (chessboard[i][j] == 'Q')
				return false;

		return true;
	}


	//第三次做
	vector<vector<string>> solveNQueens3(int n) {
		string s(n, '.');
		vector<string> board(n, s);
		res.clear();
		backtrace(board, 0, n);
		return res;
	}
	void backtrace(vector<string>& board, int row, int n) {
		if (row == n) {
			res.push_back(board);
			return;
		}

		for (int col = 0; col < n; col++) {
			if (isVaild3(board, row, col)) {
				board[row][col] = 'Q';
				backtrace(board, row + 1, n);
				board[row][col] = '.';
			}
		}
	}

	bool isVaild3(vector<string>& board, int row, int col) {
		for (int i = row - 1; i >= 0; i--) {
			if (board[i][col] == 'Q')
				return false;
		}

		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < board.size();
			i--, j++) {
			if (board[i][j] == 'Q')
				return false;
		}
		return true;
	}

	// 第四次做了
	vector<vector<string>> solveNQueens4(int n) {
		res.clear();
		string s(n, '.');
		vector<string> chessboard(n, s);
		backtracking4(chessboard, 0);
		return res;
	}
	void backtracking4(vector<string>& chessboard, int row) {
		if (row == chessboard.size()) {
			res.push_back(chessboard);
			return;
		}

		for (int i = 0; i < chessboard.size(); i++) {
			if (isValid4(chessboard, row, i)) {
				chessboard[row][i] = 'Q';
				backtracking4(chessboard, row + 1);
				chessboard[row][i] = '.';
			}
		}
	}

	bool isValid4(vector<string>& chessboard, int row, int col) {
		for (int i = 0; i < row; i++) {
			if (chessboard[i][col] == 'Q')
				return false;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
			if (chessboard[i][j] == 'Q')
				return false;

		for (int i = row - 1, j = col + 1; i >= 0 && j < chessboard.size();
			i--, j++)
			if (chessboard[i][j] == 'Q')
				return false;

		return true;
	}
};

int main() {
	Solution st;
	vector<vector<string>> res = st.solveNQueens(4);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << endl;
		cout << endl;
	}
	cout << "---------" << endl;
	vector<vector<string>> res1 = st.solveNQueens3(4);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[0].size(); j++)
			cout << res1[i][j] << endl;
		cout << endl;
	}
	cout << "---------" << endl;
	vector<vector<string>> res4 = st.solveNQueens4(5);
	for (int i = 0; i < res4.size(); i++) {
		for (int j = 0; j < res4[0].size(); j++)
			cout << res4[i][j] << endl;
		cout << endl;
	}

	return 0;
}