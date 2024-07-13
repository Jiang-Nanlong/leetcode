#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// 时间复杂度0(V+E)

int TopologicalSort() {
	int n, m;
	cin >> n >> m;
	vector<int> inDegree(n, 0);

	unordered_map<int, vector<int>> grid;  // 记录图

	int from, to;
	while (m--) {
		cin >> from >> to;
		inDegree[to]++;
		grid[from].push_back(to);
	}

	queue<int> que;   // 存放入度为0的点
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0)
			que.push(i);
	}

	vector<int> res;
	while (!que.empty()) {  // 每次出队一个入度为0的节点，并把它指向的下一个节点入度减1，如果减1后入度为0，则直接入度。时间复杂度0(V+E)
		int cur = que.front();
		que.pop();
		res.push_back(cur);

		for (auto& to : grid[cur]) {  // 把所有以当前节点为起点的终点的入度减1
			if (--inDegree[to] == 0)
				que.push(to);
		}
	}

	if (res.size() == n) {
		for (int i : res)
			cout << i << " ";
		cout << endl;
		return 0;
	}
	else {
		cout << "存在环" << endl;
		return -1;
	}
}

int main() {
	return TopologicalSort();
}