#include <iostream>
#include <vector>
using namespace std;

//这个题跟以往的回溯题不一样，没有终止条件，开始没看明白怎么结束。后来才看懂，在递归的本层把一个'.'改为数字，然后进入下一层，下一层又会从棋盘的左上角开始，找到第一个是'.'的节点，然后修改它的值。
//就这么一层层的递归，然后找出所有的节点，如果已经没有节点可供修改了，就返回true，然后就会一层层的直接返回true，就找到了我们要的
//感觉这个题有些难，想不通

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		Helper(board);
	}
	bool Helper(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					for (char k = '1'; k <= '9'; k++) {
						if (isvalid(i, j, k, board)) {
							board[i][j] = k;
							if (Helper(board)) return true;
							board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	bool isvalid(int row, int col, char k, vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			if (board[i][col] == k)
				return false;
		}

		for (int i = 0; i < 9; i++) {
			if (board[row][i] == k)
				return false;
		}

		int startrow = row / 3 * 3;
		int startcol = col / 3 * 3;
		for (int i = startrow; i < startrow + 3; i++) {
			for (int j = startcol; j < startcol + 3; j++) {
				if (board[i][j] == k)
					return false;
			}
		}
		return true;
	}
};

void main() {
	Solution st;
	vector<vector<char>> board{
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

	st.solveSudoku(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}