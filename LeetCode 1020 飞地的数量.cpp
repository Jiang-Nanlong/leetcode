#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//��������Ҫ������в��űߣ�ͬʱ���޷������½�ص�����
//���Դ������߿�ʼ�����������п���ͨ���߱�������½�ض���ɺ���Ȼ�����ͳһ����һ�Σ��������ж���½�أ��������Ľ��
//ͬ��Ҳ�ֳ�������ȱ����͹�����ȱ������ַ�ʽ

class Solution {
public:
	int numEnclaves(vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++) {
			if (grid[i][0] == 1) dfs(grid, i, 0);
			if (grid[i][grid[0].size() - 1] == 1) dfs(grid, i, grid[0].size() - 1);
		}
		for (int i = 0; i < grid[0].size(); i++) {
			if (grid[0][i] == 1) dfs(grid, 0, i);
			if (grid[grid.size() - 1][i]) dfs(grid, grid.size() - 1, i);
		}
		int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) count++;
			}
		}
		return count;
	}

	int numEnclaves1(vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++) {
			if (grid[i][0] == 1) bfs(grid, i, 0);
			if (grid[i][grid[0].size() - 1] == 1) bfs(grid, i, grid[0].size() - 1);
		}
		for (int i = 0; i < grid[0].size(); i++) {
			if (grid[0][i] == 1) bfs(grid, 0, i);
			if (grid[grid.size() - 1][i]) bfs(grid, grid.size() - 1, i);
		}
		int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) count++;
			}
		}
		return count;
	}

private:
	int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
	void dfs(vector<vector<int>>& grid, int x, int y) {
		grid[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
			if (grid[next_x][next_y] == 1)
				dfs(grid, next_x, next_y);
		}
	}
	void bfs(vector<vector<int>>& grid, int x, int y) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		grid[x][y] = 0;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first;
			int cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0], next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
				if (grid[next_x][next_y] == 1) {
					grid[next_x][next_y] = 0;
					que.push({ next_x,next_y });
				}
			}
		}
	}
};

int main() {
	Solution st;
	vector<vector<int>> grid{
		{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
		{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
		{0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
		{0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
		{0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
		{0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 1} };

	cout << st.numEnclaves(grid) << endl;
	cout << st.numEnclaves1(grid) << endl;
	return 0;
}