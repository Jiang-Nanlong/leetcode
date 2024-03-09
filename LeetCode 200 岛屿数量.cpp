#include <iostream>
#include <vector>
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
	return 0;
}