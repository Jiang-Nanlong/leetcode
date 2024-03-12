#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

//����һ��n*n�����֣������е�1��ʾ½�أ�0��ʾˮ������ֻһ�ΰ�0����1���������ĵ��������
//��ʼ��ֻ�뵽���ñ����Ľⷨ�����Ƕ���ÿһ����0�ĵ�Ϊ��㣬��ִ��һ��dfs�������ܱ�������½�ص������������������ֻ���������������
//һ����0���1֮��ȡ���ֵ���ڶ����ǵ�ͼ��û��0��ȫ��1.

//�����ⷨ������������ⷨ��ʱ�ˣ�ʱ�临�Ӷ���O(n^4)����߿϶��кö��ظ����㣬���������벻����ô�Ż�
class Solution {
public:
	int largestIsland(vector<vector<int>>& grid) {
		int sum = 0, res = 0, count0 = 0, count1 = 0;  //count0��count1����ͳ�Ƶ�ͼ��0��1�����������û��0.��ֱ�ӷ���1�����������򣬾ͷ���res
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

	//��������¼�Ľⷨ�ر���������ȱ���������ͼ����ÿ�����춼���Ϻţ�����һ�鵺��ȫ���2��һ��ȫ���3...��Ȼ����һ��map����ÿ����Ŷ�Ӧ�ĵ��������
	//Ȼ������ͷ��ʼ���������԰�ÿһ��0���1��Ȼ����ͳ�������1���ڵĵ���ı�ţ�Ȼ��ͨ����Ż�ȡ��������ˣ�ʱ�临�Ӷ���O(n^2)
	//��ʵ����Ҳ���Բ�����visited���飬grid[i][j]==1�������visited����Ĺ���
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
		unordered_set<int> ust; //��ǰ������ܿ���������ͬ�ĵ��죬�������¶��ǵ���2������set���ж�ĳ�����������Ƿ��Ѿ�����������
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 0) {
					count = 1;  //�����ϵ�ǰ�ڵ�
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
		unordered_set<int> ust; //��ǰ������ܿ���������ͬ�ĵ��죬�������¶��ǵ���2������set���ж�ĳ�����������Ƿ��Ѿ�����������
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 0) {
					count = 1;  //�����ϵ�ǰ�ڵ�
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

	//ȥ��visited�����Ժ��bfs����
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
					grid[next_x][next_y] = mark;   //����ط������˺ó�ʱ�䣬��ʼ�Ƿŵ�count++;�ϱߣ����ǽ�����ԣ����Թ���������Ϊû�м�ʱ�޸�Ϊmark�����µ�ǰ�ڵ㱻�ظ����
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