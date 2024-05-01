#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//����һ����ά����grid������1��ʾ���죬0��ʾˮ������ֻ������ˮƽ����ֱ���������ڵ�1��ɣ��������������е����������
//������˼·�������һ������������һ����ͬ��bool�͵����飬�ж��Ƿ�ÿ��λ�ö��������ˣ����ĳ��λ�ã�û�б���������������ط�ǡ������1�Ļ�����˵����������֮ǰ�Ĳ����������+1

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (visited[i][j] == false && grid[i][j] == '1') {
					visited[i][j] = true;
					count++;
					dfs(grid, visited, i, j);
				}
			}
		}
		return count;
	}

	int numIslands1(vector<vector<char>>& grid) {
		vector<vector<bool>> visited{ grid.size(),vector<bool>(grid[0].size(),false) };
		int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (visited[i][j] == false && grid[i][j] == '1') {
					count++;
					bfs(grid, visited, i, j);
				}
			}
		}
		return count;
	}

private:
	int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };  //�����ʾ�ĸ�����ķ�������֮ǰд�Ĳ�̫һ������������֮ǰ����ôд����
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
			if (visited[next_x][next_y] == false && grid[next_x][next_y] == '1') {
				visited[next_x][next_y] = true;
				dfs(grid, visited, next_x, next_y);
			}
		}
	}

	void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		visited[x][y] = true;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first, cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
				if (visited[next_x][next_y] == false && grid[next_x][next_y] == '1') {
					visited[next_x][next_y] = true;
					que.push({ next_x,next_y });
				}
			}
		}
	}

public:
	//�ڶ������������������
	int numIslands2(vector<vector<char>>& grid) {
		int count = 0;
		vector<vector<bool>> visied(grid.size(),
			vector<bool>(grid[0].size(), false));
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (visied[i][j] == false && grid[i][j] == '1') {
					count++;
					bfs1(grid, visied, i, j);
				}
			}
		}
		return count;
	}

	void bfs1(vector<vector<char>>& grid, vector<vector<bool>>& visied, int x,
		int y) {
		queue<pair<int, int>> que;
		que.push(make_pair(x, y));
		visied[x][y] = true;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first, cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
					next_y >= grid[0].size() || grid[next_x][next_y] == '0')
					continue;
				if (visied[next_x][next_y] == false) {
					que.push(make_pair(next_x, next_y));
					visied[next_x][next_y] = true;
				}
			}
		}
	}

	//�����������
	int numIslands3(vector<vector<char>>& grid) {
		int count = 0;
		vector<vector<bool>> visied(grid.size(),
			vector<bool>(grid[0].size(), false));
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (visied[i][j] == false && grid[i][j] == '1') {
					count++;
					visied[i][j] = true;
					dfs1(grid, visied, i, j);
				}
			}
		}
		return count;
	}

	void dfs1(vector<vector<char>>& grid, vector<vector<bool>>& visied, int x,
		int y) {

		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
				next_y >= grid[0].size() || grid[next_x][next_y] == '0')
				continue;
			if (visied[next_x][next_y] == false) {
				visied[next_x][next_y] = true;
				dfs1(grid, visied, next_x, next_y);
			}
		}
	}
};

int main() {
	Solution st;
	vector<vector<char>> grid{
		{ '1', '1', '1', '1', '0' },
		{ '1', '1', '0', '1', '0' },
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '0', '0', '0' } };
	vector<vector<char>> grid1{
		{'1','1','0','0','0'} ,
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'} };
	cout << st.numIslands(grid) << endl;
	cout << st.numIslands(grid1) << endl;
	cout << "---------" << endl;
	cout << st.numIslands1(grid) << endl;
	cout << st.numIslands1(grid1) << endl;
	cout << "---------" << endl;
	cout << st.numIslands2(grid) << endl;
	cout << st.numIslands2(grid1) << endl;
	cout << "---------" << endl;
	cout << st.numIslands3(grid) << endl;
	cout << st.numIslands3(grid1) << endl;
	return 0;
}