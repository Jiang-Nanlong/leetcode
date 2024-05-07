#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//����һ�����飬�����е�1��ʾ½�أ�0��ʾˮ���������ҽ���һ����½����ɵĵ��죬��õ�����ܳ���
//ͬ��Ҳ��Ϊbfs��dfs���ְ汾���������е�ÿһ��Ԫ�ض�count+=4������ÿ�½�ص��ĸ��ٱߣ���һ���ǵ���Ļ���count--��������Ǳ߽�Ļ��Ͳ��ùܡ�

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

	//����Ҳ���Բ���bfs��dfs���ͱ�������Ϊ1�Ľڵ㣬Ȼ������ĸ����򣬶�ÿ�����򵥶��ж�
	int islandPerimeter2(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					for (int k = 0; k < 4; k++) {       // ���������ĸ�����
						int x = i + dir[k][0];
						int y = j + dir[k][1];    // �����ܱ�����x,y
						if (x < 0                       // i�ڱ߽���
							|| x >= grid.size()     // i�ڱ߽���
							|| y < 0                // j�ڱ߽���
							|| y >= grid[0].size()  // j�ڱ߽���
							|| grid[x][y] == 0) {   // x,yλ����ˮ��
							result++;
						}
					}
				}
			}
		}
		return result;
	}

	//���Ǵ�������¼�����һ�ַ�����ֻҪ������½�ذ��ţ������͵ü�2���ͷֿ�ͳ���ж��ٿ�½�غͶ��ٸ����ŵġ�
	int islandPerimeter3(vector<vector<int>>& grid) {
		int sum = 0;    // ½������
		int cover = 0;  // ��������
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					sum++;
					// ͳ���ϱ�����½��
					if (i - 1 >= 0 && grid[i - 1][j] == 1) cover++;
					// ͳ���������½��
					if (j - 1 >= 0 && grid[i][j - 1] == 1) cover++;
					// Ϊʲôûͳ���±ߺ��ұߣ� ��Ϊ�����ظ����㣬�����µĽڵ���ұߺ��±߿϶��ǲ����а��ŵģ����в��ÿ���
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

	//�ڶ�����
		//��dfs��bfs���У���Ҫ�ǿ�ʲô����»��бߣ���Ҫ�����֣�ǰ�����ǵ�ǰλ�õ��������а��ű߽�ģ�Ҳ�����ĸ�������Խ��ģ�
		// ���������ĸ�������grid[next_x][next_y]==0������������һ����
		// ������ͻȻ�뵽���Ա���ÿ��λ�ã��ж������ĸ�������û�г����ϱ���������Ϳ���
public:
	int islandPerimeter4(vector<vector<int>>& grid) {
		int count = 0;
		vector<vector<bool>> visited(grid.size(),
			vector<bool>(grid[0].size(), false));
		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (grid[i][j] == 1 && visited[i][j] == false)
					dfs1(grid, visited, i, j, count);

		return count;
	}
	void dfs1(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x,
		int y, int& count) {
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
				next_y >= grid[0].size() || grid[next_x][next_y] == 0) {
				count++;
				continue;
			}
			if (grid[next_x][next_y] == 1 && visited[next_x][next_y] == false)
				dfs1(grid, visited, next_x, next_y, count);
		}
	}

	//ֱ�ӱ������нڵ㣬�ж������Ƿ��������������
	int islandPerimeter5(vector<vector<int>>& grid) {
		int count = 0;

		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (grid[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int next_x = i + dir[k][0];
						int next_y = j + dir[k][1];
						if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
							next_y >= grid[0].size() ||
							grid[next_x][next_y] == 0)
							count++;
					}
				}

		return count;
	}

	//��������¼�ķ�������̫���뵽
	int islandPerimeter6(vector<vector<int>>& grid) {
		int island = 0;  //ͳ��½������
		int cover = 0;   //ͳ�����ڵ�����
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					island++;
					if (i - 1 >= 0 && grid[i - 1][j] == 1)
						cover++;
					if (j - 1 >= 0 && grid[i][j - 1] == 1)
						cover++;
				}
			}
		}
		return island * 4 - cover * 2;
	}
};

int main() {
	Solution st;
	vector<vector<int>> grid = { {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
	cout << st.islandPerimeter(grid) << endl;
	cout << st.islandPerimeter1(grid) << endl;
	cout << st.islandPerimeter2(grid) << endl;
	cout << st.islandPerimeter3(grid) << endl;
	cout << st.islandPerimeter4(grid) << endl;
	cout << st.islandPerimeter5(grid) << endl;
	cout << st.islandPerimeter6(grid) << endl;
	return 0;
}