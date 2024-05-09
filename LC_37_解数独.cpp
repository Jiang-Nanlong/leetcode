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

	//第二次做，这次做总体思路没有问题。不过有两个地方没注意到，我开始想的是每层递归都从上一层节点继续，但是又不知道具体应该是往右还是往下，后来看了答案才知道，每层递归都是从左上角开始。
	//再就是我的backtracking函数没有返回值，这里我开始想到是不是应该跟递归二叉树搜索一条边的写法一样，有一个返回值，遇到合适的结果就直接返回。但是没有写，也不知道递归的终止条件怎么写，
	//后来看了答案知道要加返回值了，然后知道了要在哪加返回值，也就不需要终止条件了。
	void solveSudoku1(vector<vector<char>>& board) { backtracking(board); }

	bool backtracking(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.')
					continue;
				for (int k = '1'; k <= '9'; k++) {
					if (isValid1(board, i, j, k)) {
						board[i][j] = k;
						if (backtracking(board))
							return true;  //找到合适的棋盘，直接返回true
						board[i][j] = '.';
					}
				}
				return false;  //如果9个数都遍历了，都不行，直接返回false
			}
		}
		return true; //整个棋盘都遍历了一遍，运行到这里说明前边没有返回false，说民已经找到了合适的棋盘，直接返回true
	}

	bool isValid1(vector<vector<char>>& board, int row, int col, char key) {
		for (int i = 0; i < 9; i++)
			if (board[i][col] == key)
				return false;

		for (int i = 0; i < 9; i++)
			if (board[row][i] == key)
				return false;

		int newrow = row / 3 * 3;
		int newcol = col / 3 * 3;
		for (int i = newrow; i < newrow + 3; i++) {
			for (int j = newcol; j < newcol + 3; j++) {
				if (board[i][j] == key)
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
