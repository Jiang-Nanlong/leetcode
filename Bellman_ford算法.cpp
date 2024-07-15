#include <iostream>
#include <vector>
using namespace std;

// Bellman_ford算法用来解决带负权图的单源最短路径问题。
// 感觉思路比dijkstra算法简单

int Bellman_ford() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid;
	int from, to, weight;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		grid.push_back({ from,to,weight });
	}
	int start = 1, end = n;
	vector<int> minDist(n + 1, INT_MAX);
	minDist[start] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (auto& edge : grid) {
			int from = edge[0], to = edge[1], weight = edge[2];
			if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + weight)
				minDist[to] = minDist[from] + weight;
		}
	}

	if (minDist[end] == INT_MAX) {
		cout << "不可达" << endl;
		return -1;
	}
	for (int i = 1; i <= n; i++) {
		cout << minDist[i] << endl;
	}
	return 0;
}

int main() {
	return Bellman_ford();
}