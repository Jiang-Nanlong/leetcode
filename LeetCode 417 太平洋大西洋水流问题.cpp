#include <iostream>
#include <vector>
using namespace std;

//ˮֻ����С�ڻ���ڵ�ǰֵ�ĵط�������ĿҪ�����ҳ����������е�����꣬��Щ���ˮ�ȿ�������̫ƽ���ֿ�����������󣬴����������·���̫ƽ�������Ϸ�
//�о������dfs��Ҫ����ֵ�������������bool�Ļ�������ôȷ���ǵ�����̫ƽ���Ǵ����󣬻��Ƕ�������

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
private:
	int dir[4][2] = { 1,0,0,1,0,-1,-1,0 };
	//����д��������ֻ�ܿ���������¼����������һ���������ϵķ��������Ǵ�̫ƽ����ʹ��������������ϣ���������visited����
	// ���Ƚ������������ͬ�㣬��Щ����Ǽȿ��Ե�̫ƽ���ֿ��Ե�������ĵ㡣
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
	return 0;
}