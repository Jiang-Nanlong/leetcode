#include <iostream>
#include <vector>
using namespace std;

//�����������Ļ����ⲻһ����û����ֹ��������ʼû��������ô�����������ſ������ڵݹ�ı����һ��'.'��Ϊ���֣�Ȼ�������һ�㣬��һ���ֻ�����̵����Ͻǿ�ʼ���ҵ���һ����'.'�Ľڵ㣬Ȼ���޸�����ֵ��
//����ôһ���ĵݹ飬Ȼ���ҳ����еĽڵ㣬����Ѿ�û�нڵ�ɹ��޸��ˣ��ͷ���true��Ȼ��ͻ�һ����ֱ�ӷ���true�����ҵ�������Ҫ��
//�о��������Щ�ѣ��벻ͨ

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

	//�ڶ����������������˼·û�����⡣�����������ط�ûע�⵽���ҿ�ʼ�����ÿ��ݹ鶼����һ��ڵ�����������ֲ�֪������Ӧ�������һ������£��������˴𰸲�֪����ÿ��ݹ鶼�Ǵ����Ͻǿ�ʼ��
	//�پ����ҵ�backtracking����û�з���ֵ�������ҿ�ʼ�뵽�ǲ���Ӧ�ø��ݹ����������һ���ߵ�д��һ������һ������ֵ���������ʵĽ����ֱ�ӷ��ء�����û��д��Ҳ��֪���ݹ����ֹ������ôд��
	//�������˴�֪��Ҫ�ӷ���ֵ�ˣ�Ȼ��֪����Ҫ���ļӷ���ֵ��Ҳ�Ͳ���Ҫ��ֹ�����ˡ�
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
							return true;  //�ҵ����ʵ����̣�ֱ�ӷ���true
						board[i][j] = '.';
					}
				}
				return false;  //���9�����������ˣ������У�ֱ�ӷ���false
			}
		}
		return true; //�������̶�������һ�飬���е�����˵��ǰ��û�з���false��˵���Ѿ��ҵ��˺��ʵ����̣�ֱ�ӷ���true
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