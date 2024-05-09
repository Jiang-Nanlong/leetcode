#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
//我想的是先复制一个一模一样的数组temp，然后从四个边框开始遍历，如果遇到O就变成X，最后和board对比，temp中为O的位置说明就是被包围的地方，然后把board中的这些变成X就行了
//但是代码随想录里说了一种空间复杂度更低的方法，不用复制数组，只需要在board数组中把靠着边界的O变成除了X和O之外的字母，最后重新遍历数组，如果一个位置是A说明它可以通过边界访问的O，重新修改成O就行。
// 如果一个位置是O说明就是被包围的，修改成X就行。
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		vector<vector<char>> temp(board);
		for (int i = 0; i < board.size(); i++) {
			if (temp[i][0] == 'O') dfs(temp, i, 0);
			if (temp[i][board[0].size() - 1] == 'O') dfs(temp, i, board[0].size() - 1);
		}
		for (int i = 0; i < board[0].size(); i++) {
			if (temp[0][i] == 'O') dfs(temp, 0, i);
			if (temp[board.size() - 1][i] == 'O') dfs(temp, board.size() - 1, i);
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (temp[i][j] == 'O')
					board[i][j] = 'X';
			}
		}
	}

	void solve1(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			if (board[i][0] == 'O') dfs1(board, i, 0);
			if (board[i][board[0].size() - 1] == 'O') dfs1(board, i, board[0].size() - 1);
		}
		for (int i = 0; i < board[0].size(); i++) {
			if (board[0][i] == 'O') dfs1(board, 0, i);
			if (board[board.size() - 1][i] == 'O') dfs1(board, board.size() - 1, i);
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';  //注意这两个if的顺序不要搞混
				if (board[i][j] == 'A') board[i][j] = 'O';
			}
		}
	}

	//bfs版本
	void solve2(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			if (board[i][0] == 'O') bfs(board, i, 0);
			if (board[i][board[0].size() - 1] == 'O') bfs(board, i, board[0].size() - 1);
		}
		for (int i = 0; i < board[0].size(); i++) {
			if (board[0][i] == 'O') bfs(board, 0, i);
			if (board[board.size() - 1][i] == 'O') bfs(board, board.size() - 1, i);
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';  //注意这两个if的顺序不要搞混
				if (board[i][j] == 'A') board[i][j] = 'O';
			}
		}
	}

private:
	int dir[4][2] = { 1,0,0,1,0,-1,-1,0 };
	void dfs(vector<vector<char>>& board, int x, int y) {
		board[x][y] = 'X';
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size()) continue;
			if (board[next_x][next_y] == 'O') {
				dfs(board, next_x, next_y);
			}
		}
	}


	void dfs1(vector<vector<char>>& board, int x, int y) {
		board[x][y] = 'A';  //把可以通过边界访问的O都修改成A
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size()) continue;
			if (board[next_x][next_y] == 'O') {
				dfs1(board, next_x, next_y);
			}
		}
	}

	void bfs(vector<vector<char>>& board, int x, int y) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		board[x][y] = 'A';
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first, cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size()) continue;
				if (board[next_x][next_y] == 'O') {
					board[next_x][next_y] = 'A';
					que.push({ next_x,next_y });
				}
			}
		}
	}

public:
	//第二次做
	//深度优先搜索
	void solve3(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			if (board[i][0] == 'O')
				dfs2(board, i, 0);
			if (board[i][board[0].size() - 1] == 'O')
				dfs2(board, i, board[0].size() - 1);
		}
		for (int i = 0; i < board[0].size(); i++) {
			if (board[0][i] == 'O')
				dfs2(board, 0, i);
			if (board[board.size() - 1][i] == 'O')
				dfs2(board, board.size() - 1, i);
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == 'A')
					board[i][j] = 'O';
			}
		}
	}
	void dfs2(vector<vector<char>>& board, int x, int y) {
		board[x][y] = 'A';
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= board.size() || next_y < 0 ||
				next_y >= board[0].size())
				continue;
			if (board[next_x][next_y] == 'O') {
				dfs2(board, next_x, next_y);
			}
		}
	}

	//广度优先搜索
	void solve4(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			if (board[i][0] == 'O')
				bfs1(board, i, 0);
			if (board[i][board[0].size() - 1] == 'O')
				bfs1(board, i, board[0].size() - 1);
		}
		for (int i = 0; i < board[0].size(); i++) {
			if (board[0][i] == 'O')
				bfs1(board, 0, i);
			if (board[board.size() - 1][i] == 'O')
				bfs1(board, board.size() - 1, i);
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == 'A')
					board[i][j] = 'O';
			}
		}
	}
	void bfs1(vector<vector<char>>& board, int x, int y) {
		board[x][y] = 'A';
		queue<pair<int, int>> que;
		que.push(make_pair(x, y));
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first, cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= board.size() || next_y < 0 ||
					next_y >= board[0].size())
					continue;
				if (board[next_x][next_y] == 'O') {
					board[next_x][next_y] = 'A';
					que.push(make_pair(next_x, next_y));
				}
			}
		}
	}
};

int main() {
	Solution st;
	vector<vector<char>>board = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}
	};
	st.solve(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------" << endl;

	vector<vector<char>>board1 = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}
	};
	st.solve1(board1);
	for (int i = 0; i < board1.size(); i++) {
		for (int j = 0; j < board1[0].size(); j++) {
			cout << board1[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------" << endl;

	vector<vector<char>>board2 = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}
	};
	st.solve2(board2);
	for (int i = 0; i < board2.size(); i++) {
		for (int j = 0; j < board2[0].size(); j++) {
			cout << board2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}