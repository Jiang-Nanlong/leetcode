#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

//给定一个n*n的数字，数组中的1表示陆地，0表示水，尝试只一次把0换成1，返回最大的岛屿的数量
//开始我只想到了用暴力的解法，就是对于每一个是0的点为起点，都执行一遍dfs，返回能遍历到的陆地的数量，最后最大的数量只可能是两种情况：
//一种是0变成1之后取最大值，第二种是地图中没有0，全是1.

//暴力解法，很明显这个解法超时了，时间复杂度是O(n^4)，里边肯定有好多重复计算，但是我又想不出怎么优化
class Solution {
public:
	int largestIsland(vector<vector<int>>& grid) {
		int sum = 0, res = 0, count0 = 0, count1 = 0;  //count0和count1用来统计地图中0和1的数量，如果没有0.就直接返回1的数量。否则，就返回res
		res = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 1) count1++;
				sum = 0;
				vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
				if (grid[i][j] == 0) {
					count0++;
					grid[i][j] = 1;
					visited[i][j] = true;
					dfs(grid, visited, i, j, sum);
					grid[i][j] = 0;

				}
				res = max(res, sum);
			}
		}
		if (count0 == 0) return count1;
		return res;
	}

	//代码随想录的解法特别巧妙，就是先遍历整个地图，把每个岛屿都标上号，比如一块岛屿全标成2，一块全标成3...，然后用一个map保存每个标号对应的岛屿面积。
	//然后再重头开始遍历，尝试把每一个0变成1，然后再统计与这个1相邻的岛屿的标号，然后通过标号获取面积就行了，时间复杂度是O(n^2)
	//其实这里也可以不设置visited数组，grid[i][j]==1就替代了visited数组的功能
	int largestIsland1(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
		unordered_map<int, int> ump;
		int count = 0;
		int mark = 2;
		bool isAllIsland = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 0) isAllIsland = false;

				if (visited[i][j] == false && grid[i][j] == 1) {
					dfs1(grid, visited, i, j, count, mark);
					ump[mark] = count;
					mark++;
					count = 0;
				}
			}
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				cout << grid[i][j] << "  ";
			}
			cout << endl;
		}
		if (isAllIsland) return grid.size() * grid.size();

		int res = 0;
		unordered_set<int> ust; //当前点的四周可能是有相同的岛屿，比如上下都是岛屿2，引入set来判断某个岛屿的面积是否已经计算在内了
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 0) {
					count = 1;  //计算上当前节点
					ust.clear();
					for (int k = 0; k < 4; k++) {
						int next_i = i + dir[k][0];
						int next_j = j + dir[k][1];
						if (next_i < 0 || next_i >= grid.size() || next_j < 0 || next_j >= grid.size()) continue;
						if (ust.count(grid[next_i][next_j])) continue;
						count += ump[grid[next_i][next_j]];
						ust.insert(grid[next_i][next_j]);
					}
				}
				res = max(res, count);
			}
		}
		return res;
	}

	int largestIsland2(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
		unordered_map<int, int> ump;
		int count = 0;
		int mark = 2;
		bool isAllIsland = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 0) isAllIsland = false;

				if (visited[i][j] == false && grid[i][j] == 1) {
					bfs(grid, visited, i, j, count, mark);
					ump[mark] = count;
					cout << "count:" << count << endl;
					mark++;
					count = 0;
				}
			}
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				cout << grid[i][j] << "  ";
			}
			cout << endl;
		}
		if (isAllIsland) return grid.size() * grid.size();

		int res = 0;
		unordered_set<int> ust; //当前点的四周可能是有相同的岛屿，比如上下都是岛屿2，引入set来判断某个岛屿的面积是否已经计算在内了
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 0) {
					count = 1;  //计算上当前节点
					ust.clear();
					for (int k = 0; k < 4; k++) {
						int next_i = i + dir[k][0];
						int next_j = j + dir[k][1];
						if (next_i < 0 || next_i >= grid.size() || next_j < 0 || next_j >= grid.size()) continue;
						if (ust.count(grid[next_i][next_j])) continue;
						count += ump[grid[next_i][next_j]];
						ust.insert(grid[next_i][next_j]);
					}
				}
				res = max(res, count);
			}
		}
		return res;
	}
private:
	int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
	void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& sum) {
		sum++;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid.size()) continue;
			if (visited[next_x][next_y] == false && grid[next_x][next_y] == 1) {
				visited[next_x][next_y] = true;
				dfs(grid, visited, next_x, next_y, sum);
			}
		}
	}

	void dfs1(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count, int mark) {
		count++;
		grid[x][y] = mark;
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid.size()) continue;
			if (visited[next_x][next_y] == false && grid[next_x][next_y] == 1) {
				dfs1(grid, visited, next_x, next_y, count, mark);
			}
		}
	}

	void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count, int mark) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first;
			int cur_y = cur.second;
			grid[cur_x][cur_y] = mark;
			count++;

			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid.size()) continue;
				if (visited[next_x][next_y] == false && grid[next_x][next_y] == 1) {
					visited[next_x][next_y] = true;
					que.push({ next_x,next_y });
				}
			}
		}
	}

	//去掉visited数组以后的bfs代码
	void bfs1(vector<vector<int>>& grid, int x, int y, int& count, int mark) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		grid[x][y] = mark;

		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first;
			int cur_y = cur.second;
			count++;

			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid.size()) continue;
				if (grid[next_x][next_y] == 1) {
					grid[next_x][next_y] = mark;   //这个地方调试了好长时间，开始是放到count++;上边，但是结果不对，调试过后发现是因为没有及时修改为mark，导致当前节点被重复添加
					que.push({ next_x,next_y });
				}
			}
		}
	}
};

int main() {
	Solution st;
	vector<vector<int>> grid1{
		{1, 0, 0, 1, 1},
		{1, 0, 0, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 1, 0}
	};
	cout << st.largestIsland1(grid1) << endl;
	vector<vector<int>> grid2{
		{1, 0, 0, 1, 1},
		{1, 0, 0, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 1, 0}
	};
	vector<vector<int>> grid3{ {1,1},{1,0} };
	cout << st.largestIsland2(grid2) << endl;
	cout << st.largestIsland2(grid3) << endl;
	return 0;
}
