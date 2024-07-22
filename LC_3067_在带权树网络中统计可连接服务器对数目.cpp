#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// 这个程序调试了三天，感觉身心疲惫
// edges是一个多叉树

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
		for (int i = 0; i <= n; i++) {  // 以图中的每一个节点作为根节点
			vector<bool> visited(n + 1, false);
			visited[i] = true;
			temp.push_back({});  // 用来存放根节点的每个子树中可以通往根节点的节点的数目
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

	// 递归访问每一个子树
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

	// 根据claude优化了一下代码，和之前代码的时间复杂度是一样的，但是代码上更简洁，没有使用visited数组和temp数组。
	// 在dfs时传入当前节点和当前节点的父节点，在以当前节点为根节点时，防止当前节点的下一个节点是根节点的父节点。也就是只能往下遍历，不能往上回到父节点。就相当于visited数组的作用了
	// dfs有返回值，每次都通过dfs返回值计算结果，避免了使用temp数组
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
				if (edge.first != father) {   // 避免下一个节点回到父节点
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