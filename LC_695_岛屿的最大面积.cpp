#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<vector<bool>>  visited(grid.size(), vector<bool>(grid[0].size(), false));
		int count = 0, res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (visited[i][j] == false && grid[i][j] == 1) {
					dfs(grid, visited, i, j, count);
					res = max(res, count);
					count = 0;
				}
			}
		}
		return res;
	}

	int maxAreaOfIsland1(vector<vector<int>>& grid) {
		vector<vector<bool>>  visited(grid.size(), vector<bool>(grid[0].size(), false));
		int count = 0, res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (visited[i][j] == false && grid[i][j] == 1) {
					bfs(grid, visited, i, j, count);
					res = max(res, count);
					count = 0;
				}
			}
		}
		return res;
	}


	int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
	void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
		visited[x][y] = true;
		count++;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
			if (visited[next_x][next_y] == false && grid[next_x][next_y] == 1) {
				dfs(grid, visited, next_x, next_y, count);
			}
		}
	}

	void bfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		visited[x][y] = true;
		count++;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first, cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
				if (visited[next_x][next_y] == false && grid[next_x][next_y] == 1) {
					visited[next_x][next_y] = true;
					count++;
					que.push({ next_x,next_y });
				}
			}
		}
	}

	//第二次做
	//深度优先搜索
	int maxAreaOfIsland2(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(),
			vector<bool>(grid[0].size(), false));
		int count = 0, res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (visited[i][j] == false && grid[i][j] == 1) {
					dfs1(grid, visited, i, j, count);
					res = max(res, count);
					count = 0;
				}
			}
		}
		return res;
	}

	void dfs1(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
		visited[x][y] = true;
		count++;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
				next_y >= grid[0].size() || grid[next_x][next_y] == 0)
				continue;
			if (visited[next_x][next_y] == false) {
				dfs1(grid, visited, next_x, next_y, count);
			}
		}
	}

	//广度优先搜索
	int maxAreaOfIsland3(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(),
			vector<bool>(grid[0].size(), false));
		int count = 0, res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (visited[i][j] == false && grid[i][j] == 1) {
					bfs1(grid, visited, i, j, count);
					res = max(res, count);
					count = 0;
				}
			}
		}
		return res;
	}

	void bfs1(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
		queue<pair<int, int>> que;
		que.push(make_pair(x, y));
		visited[x][y] = true;
		count++;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first;
			int cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
					next_y >= grid[0].size() || grid[next_x][next_y] == 0)
					continue;
				if (visited[next_x][next_y] == false) {
					visited[next_x][next_y] = true;
					count++;
					que.push(make_pair(next_x, next_y));
				}
			}
		}
	}
};

int main() {
	Solution st;
	vector<vector<int>> grid{
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0} };
	cout << st.maxAreaOfIsland(grid) << endl;
	cout << st.maxAreaOfIsland1(grid) << endl;
	cout << st.maxAreaOfIsland2(grid) << endl;
	cout << st.maxAreaOfIsland3(grid) << endl;
	return 0;
}