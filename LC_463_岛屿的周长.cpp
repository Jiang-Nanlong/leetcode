#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//给定一个数组，数组中的1表示陆地，0表示水。其中有且仅有一块由陆地组成的岛屿，求该岛屿的周长。
//同样也分为bfs和dfs两种版本，给队列中的每一个元素都count+=4，如果该块陆地的四个临边，有一个是岛屿的话就count--，而如果是边界的话就不用管。

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1 && visited[i][j] == false) {
					bfs(grid, visited, i, j, count);
				}
			}
		}
		return count;
	}

	int islandPerimeter1(vector<vector<int>>& grid) {
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int count = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1 && visited[i][j] == false) {
					dfs(grid, visited, i, j, count);
				}
			}
		}
		return count;
	}

	//或者也可以不用bfs和dfs，就遍历所有为1的节点，然后遍历四个方向，对每个方向单独判断
	int islandPerimeter2(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					for (int k = 0; k < 4; k++) {       // 上下左右四个方向
						int x = i + dir[k][0];
						int y = j + dir[k][1];    // 计算周边坐标x,y
						if (x < 0                       // i在边界上
							|| x >= grid.size()     // i在边界上
							|| y < 0                // j在边界上
							|| y >= grid[0].size()  // j在边界上
							|| grid[x][y] == 0) {   // x,y位置是水域
							result++;
						}
					}
				}
			}
		}
		return result;
	}

	//这是代码随想录提的另一种方法，只要有两个陆地挨着，边数就得减2。就分开统计有多少块陆地和多少个挨着的。
	int islandPerimeter3(vector<vector<int>>& grid) {
		int sum = 0;    // 陆地数量
		int cover = 0;  // 相邻数量
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					sum++;
					// 统计上边相邻陆地
					if (i - 1 >= 0 && grid[i - 1][j] == 1) cover++;
					// 统计左边相邻陆地
					if (j - 1 >= 0 && grid[i][j - 1] == 1) cover++;
					// 为什么没统计下边和右边？ 因为避免重复计算，最右下的节点的右边和下边肯定是不会有挨着的，所有不用考虑
				}
			}
		}
		return sum * 4 - cover * 2;
	}
private:
	int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
	void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		visited[x][y] = true;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			count += 4;
			int cur_x = cur.first;
			int cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
				if (grid[next_x][next_y] == 1) {
					count--;
					if (visited[next_x][next_y] == false) {
						visited[next_x][next_y] = true;
						que.push({ next_x,next_y });
					}
				}
			}
		}
	}

	void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
		visited[x][y] = true;
		count += 4;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
			if (grid[next_x][next_y] == 1) {
				count--;
				if (visited[next_x][next_y] == false)
					dfs(grid, visited, next_x, next_y, count);
			}
		}
	}
};

int main() {
	Solution st;
	vector<vector<int>> grid = { {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
	cout << st.islandPerimeter(grid) << endl;
	cout << st.islandPerimeter1(grid) << endl;
	cout << st.islandPerimeter2(grid) << endl;
	cout << st.islandPerimeter3(grid) << endl;
	return 0;
}
