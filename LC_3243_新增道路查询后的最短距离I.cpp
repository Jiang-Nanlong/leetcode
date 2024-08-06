#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

	// 广度优先搜索
	vector<int> shortestDistanceAfterQueries(int n,
		vector<vector<int>>& queries) {
		vector<vector<int>> grid(n);
		for (int i = 0; i < n - 1; i++)
			grid[i].push_back(i + 1);

		auto bfs = [&]() {
			vector<int> minDist(n, -1);
			queue<int> que;
			que.push(0);
			minDist[0] = 0;

			while (!que.empty()) {
				int cur = que.front();
				que.pop();
				for (int i : grid[cur]) {
					if (minDist[i] == -1) {
						minDist[i] = minDist[cur] + 1;
						que.push(i);
					}
				}
			}
			return minDist[n - 1];
			};

		vector<int> res;
		for (auto& v : queries) {
			grid[v[0]].push_back(v[1]);
			res.push_back(bfs());
		}
		return res;
	}


	// 最开始用dijkstra算法做的
	// 后来才发现，其实这里的权重都是1，这样dijkstra也基本上变成广度优先搜索了
	vector<vector<pair<int, int>>> grid;
	vector<int> minDist;
	vector<bool> visited;

	int dijkstra(int n) {
		fill(minDist.begin(), minDist.end(), -1);
		fill(visited.begin(), visited.end(), false);

		int start = 0;
		int end = n - 1;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		pq.emplace(pair<int, int>(0, 0));

		minDist[start] = 0;

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			if (visited[cur.second])
				continue;
			visited[cur.second] = true;
			for (auto& e : grid[cur.second]) {
				if (!visited[e.first]) {
					int time = minDist[cur.second] + e.second;
					if (minDist[e.first] == -1 || minDist[e.first] > time) {
						minDist[e.first] = time;
						pq.emplace(pair<int, int>(time, e.first));
					}
				}
			}
		}
		return minDist[end];
	}
	vector<int> shortestDistanceAfterQueries1(int n, vector<vector<int>>& queries) {
		grid = vector<vector<pair<int, int>>>(n);
		minDist = vector<int>(n, -1);
		visited = vector<bool>(n, false);

		for (int i = 0; i < n - 1; i++) {
			grid[i].push_back({ i + 1, 1 });
		}
		vector<int> res;
		for (int i = 0; i < queries.size(); i++) {
			auto cur = queries[i];
			grid[cur[0]].push_back({ cur[1], 1 });
			int minlen = dijkstra(n);
			res.push_back(minlen);
		}

		return res;
	}
};

int main() {
	Solution st;
	int n = 5;
	vector<vector<int>> queries{ {2,4},{0,2},{0,4} };
	vector<int> res = st.shortestDistanceAfterQueries(n, queries);
	for (int i : res)
		cout << i << " ";
	cout << endl;

	vector<int> res1 = st.shortestDistanceAfterQueries(n, queries);
	for (int i : res1)
		cout << i << " ";
	cout << endl;

	return 0;
}