#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//ˮֻ����С�ڻ���ڵ�ǰֵ�ĵط�������ĿҪ�����ҳ����������е�����꣬��Щ���ˮ�ȿ�������̫ƽ���ֿ�����������󣬴����������·���̫ƽ�������Ϸ�
//�о������dfs��Ҫ����ֵ�������������bool�Ļ�������ôȷ���ǵ�����̫ƽ���Ǵ����󣬻��Ƕ�������
//����д��������ֻ�ܿ���������¼����������һ���������ϵķ��������Ǵ�̫ƽ����ʹ��������������ϣ���������visited����
//���Ƚ������������ͬ�㣬��Щ����Ǽȿ��Ե�̫ƽ���ֿ��Ե�������ĵ㡣
//���Ƿ�Ϊdfs��bfs���ְ汾
//��������ⷨ��ʱ�临�Ӷ���O(m*n)����Ϊdfs��ʱ�临�Ӷ���O(m*n)��Ȼ�����������ͷ����forѭ����������ÿ����߱���������dfs��ʱ�临�Ӷ��� n * (n * m) + m * (n * m)��
//������Ϊ��visited����Ĵ��ڣ�ÿ��λ��ֻ�����һ�Σ���������forѭ�����dfs(heights, visited_pacific, i, 0)��dfs(heights, visited_pacific, 0, i)���Կ���һ�飬һ������һ������
//dfs(heights, visited_attlantic, i, heights[0].size() - 1)��dfs(heights, visited_attlantic, heights.size() - 1, i)���Կ���һ�飬һ������һ�����飬����ͷ����forѭ����ʱ�临�Ӷ���ʵ��2*m*n��
//����˫��forѭ����ʱ�临�Ӷ���m*n����������ܵ�ʱ�临�Ӷ���O(m*n)��

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<int>> res;
		vector<vector<bool>> visited_pacific(heights.size(), vector<bool>(heights[0].size(), false));
		vector<vector<bool>> visited_attlantic(heights.size(), vector<bool>(heights[0].size(), false));

		for (int i = 0; i < heights.size(); i++) {
			dfs(heights, visited_pacific, i, 0);
			dfs(heights, visited_attlantic, i, heights[0].size() - 1);
		}
		for (int i = 0; i < heights[0].size(); i++) {
			dfs(heights, visited_pacific, 0, i);
			dfs(heights, visited_attlantic, heights.size() - 1, i);
		}
		for (int i = 0; i < heights.size(); i++) {
			for (int j = 0; j < heights[0].size(); j++) {
				if (visited_attlantic[i][j] == true && visited_pacific[i][j] == true) {
					res.push_back({ i,j });
				}
			}
		}
		return res;
	}

	vector<vector<int>> pacificAtlantic1(vector<vector<int>>& heights) {
		vector<vector<int>> res;
		vector<vector<bool>> visited_pacific(heights.size(), vector<bool>(heights[0].size(), false));
		vector<vector<bool>> visited_attlantic(heights.size(), vector<bool>(heights[0].size(), false));

		for (int i = 0; i < heights.size(); i++) {
			bfs(heights, visited_pacific, i, 0);
			bfs(heights, visited_attlantic, i, heights[0].size() - 1);
		}
		for (int i = 0; i < heights[0].size(); i++) {
			bfs(heights, visited_pacific, 0, i);
			bfs(heights, visited_attlantic, heights.size() - 1, i);
		}

		for (int i = 0; i < heights.size(); i++) {
			for (int j = 0; j < heights[0].size(); j++) {
				if (visited_attlantic[i][j] == true && visited_pacific[i][j] == true) {
					res.push_back({ i,j });
				}
			}
		}
		return res;
	}
private:
	int dir[4][2] = { 1,0,0,1,0,-1,-1,0 };

	//int dfs(vector<vector<int>>& heights, int x, int y) {
	//	if ((x == heights.size() - 1 && y == 0) || (x == 0 && y == heights[0].size() - 1)) return 5;
	//	else if (x == 0 || y == 0) return 2;
	//	else if (x == heights.size() - 1 || y == heights[0].size() - 1) return 3;
	//	else return 0;

	//	for (int i = 0; i < 4; i++) {
	//		int next_x = x + dir[i][0];
	//		int next_y = y + dir[i][1];
	//		if (heights[next_x][next_y] < heights[x][y])
	//			dfs(heights, next_x, next_y);
	//	}
	//	//return 0;
	//}
	void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= heights.size() || next_y < 0 || next_y >= heights[0].size()) continue;
			if (visited[next_x][next_y] == false && heights[next_x][next_y] >= heights[x][y])
				dfs(heights, visited, next_x, next_y);
		}
	}
	void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
		queue<pair<int, int>> que;
		que.push({ x,y });
		visited[x][y] = true;
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first;
			int cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0], next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= heights.size() || next_y < 0 || next_y >= heights[0].size()) continue;
				if (visited[next_x][next_y] == false && heights[next_x][next_y] >= heights[cur_x][cur_y]) {
					visited[next_x][next_y] = true;
					que.push({ next_x,next_y });
				}
			}
		}
	}
public:
	//�ڶ�����
	//�����������
	vector<vector<int>> pacificAtlantic2(vector<vector<int>>& heights) {
		vector<vector<bool>> visited1(heights.size(), vector<bool>(heights[0].size(), false));
		vector<vector<bool>> visited2(heights.size(), vector<bool>(heights[0].size(), false));
		for (int i = 0; i < heights.size(); i++) {
			if (visited1[i][0] == false)
				dfs1(heights, visited1, i, 0);
			if (visited2[i][heights[0].size() - 1] == false)
				dfs1(heights, visited2, i, heights[0].size() - 1);
		}

		for (int i = 0; i < heights[0].size(); i++) {
			if (visited1[0][i] == false)
				dfs1(heights, visited1, 0, i);
			if (visited2[heights.size() - 1][i] == false)
				dfs1(heights, visited2, heights.size() - 1, i);
		}
		vector<vector<int>> res;
		for (int i = 0; i < heights.size(); i++) {
			for (int j = 0; j < heights[0].size(); j++) {
				if (visited1[i][j] == true && visited2[i][j] == true) {
					res.push_back({ i, j });
				}
			}
		}
		return res;
	}

	void dfs1(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x < 0 || next_x >= heights.size() || next_y < 0 ||
				next_y >= heights[0].size())
				continue;
			if (visited[next_x][next_y] == false &&
				heights[next_x][next_y] >= heights[x][y]) {
				dfs1(heights, visited, next_x, next_y);
			}
		}
	}

	//�����������
	vector<vector<int>> pacificAtlantic3(vector<vector<int>>& heights) {
		vector<vector<bool>> visited1(heights.size(),
			vector<bool>(heights[0].size(), false));
		vector<vector<bool>> visited2(heights.size(),
			vector<bool>(heights[0].size(), false));
		for (int i = 0; i < heights.size(); i++) {
			if (visited1[i][0] == false)
				bfs1(heights, visited1, i, 0);
			if (visited2[i][heights[0].size() - 1] == false)
				bfs1(heights, visited2, i, heights[0].size() - 1);
		}

		for (int i = 0; i < heights[0].size(); i++) {
			if (visited1[0][i] == false)
				bfs1(heights, visited1, 0, i);
			if (visited2[heights.size() - 1][i] == false)
				bfs1(heights, visited2, heights.size() - 1, i);
		}
		vector<vector<int>> res;
		for (int i = 0; i < heights.size(); i++) {
			for (int j = 0; j < heights[0].size(); j++) {
				if (visited1[i][j] == true && visited2[i][j] == true) {
					res.push_back({ i, j });
				}
			}
		}
		return res;
	}

	void bfs1(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x,
		int y) {
		visited[x][y] = true;
		queue<pair<int, int>> que;
		que.push(make_pair(x, y));
		while (!que.empty()) {
			pair<int, int> cur = que.front();
			que.pop();
			int cur_x = cur.first, cur_y = cur.second;
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (next_x < 0 || next_x >= heights.size() || next_y < 0 ||
					next_y >= heights[0].size())
					continue;
				if (visited[next_x][next_y] == false &&
					heights[next_x][next_y] >= heights[cur_x][cur_y]) {
					visited[next_x][next_y] = true;
					que.push(make_pair(next_x, next_y));
				}
			}
		}
	}
};

int main() {
	Solution st;
	vector<vector<int>> heights{
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
		{5, 1, 1, 2, 4}
	};
	vector<vector<int>>res = st.pacificAtlantic(heights);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "------------------" << endl;
	vector<vector<int>> heights1{
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
		{5, 1, 1, 2, 4}
	};
	vector<vector<int>>res1 = st.pacificAtlantic1(heights1);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[0].size(); j++) {
			cout << res1[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "------------------" << endl;
	vector<vector<int>> heights2{
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
		{5, 1, 1, 2, 4}
	};
	vector<vector<int>>res2 = st.pacificAtlantic2(heights2);
	for (int i = 0; i < res2.size(); i++) {
		for (int j = 0; j < res2[0].size(); j++) {
			cout << res2[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "------------------" << endl;
	vector<vector<int>> heights3{
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
		{5, 1, 1, 2, 4}
	};
	vector<vector<int>>res3 = st.pacificAtlantic3(heights3);
	for (int i = 0; i < res3.size(); i++) {
		for (int j = 0; j < res3[0].size(); j++) {
			cout << res3[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}