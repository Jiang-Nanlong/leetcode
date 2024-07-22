#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// ���������������죬�о�����ƣ��
// edges��һ�������

class Solution {
public:
	vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
		int n = edges.size();
		vector<vector<pair<int, int>>> grid(n + 1);
		for (auto& edge : edges) {
			grid[edge[0]].push_back({ edge[1], edge[2] });
			grid[edge[1]].push_back({ edge[0], edge[2] });
		}

		vector<int> res;
		vector<vector<int>> temp;
		for (int i = 0; i <= n; i++) {  // ��ͼ�е�ÿһ���ڵ���Ϊ���ڵ�
			vector<bool> visited(n + 1, false);
			visited[i] = true;
			temp.push_back({});  // ������Ÿ��ڵ��ÿ�������п���ͨ�����ڵ�Ľڵ����Ŀ
			int edge_num = grid[i].size();
			int count;
			for (int j = 0; j < edge_num; j++) {
				if (!visited[grid[i][j].first]) {
					count = 0;
					backtracking(grid, grid[i][j].first, count, visited, signalSpeed, grid[i][j].second);
					temp[i].push_back(count);
				}
			}
			int total_sum = 0;
			for (int j = 1; j < temp[i].size(); j++) {
				total_sum += temp[i][j] * temp[i][j - 1];
				temp[i][j] += temp[i][j - 1];
			}
			res.push_back(total_sum);
		}
		return res;
	}

	// �ݹ����ÿһ������
	void backtracking(vector<vector<pair<int, int>>>& grid, int root, int& count, vector<bool>& visited, int signalSpeed, int cost) {
		if (cost % signalSpeed == 0)
			count++;
		visited[root] = true;
		for (auto& edge : grid[root]) {
			if (!visited[edge.first]) {
				backtracking(grid, edge.first, count, visited, signalSpeed, cost + edge.second);
			}
		}
	}

	// ����claude�Ż���һ�´��룬��֮ǰ�����ʱ�临�Ӷ���һ���ģ����Ǵ����ϸ���࣬û��ʹ��visited�����temp���顣
	// ��dfsʱ���뵱ǰ�ڵ�͵�ǰ�ڵ�ĸ��ڵ㣬���Ե�ǰ�ڵ�Ϊ���ڵ�ʱ����ֹ��ǰ�ڵ����һ���ڵ��Ǹ��ڵ�ĸ��ڵ㡣Ҳ����ֻ�����±������������ϻص����ڵ㡣���൱��visited�����������
	// dfs�з���ֵ��ÿ�ζ�ͨ��dfs����ֵ��������������ʹ��temp����
	vector<int> countPairsOfConnectableServers1(vector<vector<int>>& edges, int signalSpeed) {
		int n = edges.size();
		vector<vector<pair<int, int>>> grid(n + 1);
		for (auto& edge : edges) {
			grid[edge[0]].push_back({ edge[1], edge[2] });
			grid[edge[1]].push_back({ edge[0], edge[2] });
		}

		vector<int> res(n + 1, 0);
		function<int(int, int, int)> dfs = [&](int node, int father, int cost) {
			int count = cost % signalSpeed == 0;
			for (const auto& edge : grid[node]) {
				if (edge.first != father) {   // ������һ���ڵ�ص����ڵ�
					count += dfs(edge.first, node, cost + edge.second);
				}
			}
			return count;
			};

		for (int i = 0; i <= n; i++) {
			int cost = 0, precost = 0;
			for (const auto& edge : grid[i]) {
				int count = dfs(edge.first, i, edge.second);
				cost += precost * count;
				precost += count;
			}
			res[i] = cost;
		}

		return res;
	}

};

int main() {
	Solution st;
	vector<vector<int>> grid{ {0,6,3},{6,5,3},{0,3,1},{3,2,7},{3,1,6},{3,4,2} };
	int signalSpeed = 3;
	vector<int> res = st.countPairsOfConnectableServers1(grid, signalSpeed);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}