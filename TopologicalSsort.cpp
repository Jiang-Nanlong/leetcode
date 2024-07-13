#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// ʱ�临�Ӷ�0(V+E)

int TopologicalSort() {
	int n, m;
	cin >> n >> m;
	vector<int> inDegree(n, 0);

	unordered_map<int, vector<int>> grid;  // ��¼ͼ

	int from, to;
	while (m--) {
		cin >> from >> to;
		inDegree[to]++;
		grid[from].push_back(to);
	}

	queue<int> que;   // ������Ϊ0�ĵ�
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0)
			que.push(i);
	}

	vector<int> res;
	while (!que.empty()) {  // ÿ�γ���һ�����Ϊ0�Ľڵ㣬������ָ�����һ���ڵ���ȼ�1�������1�����Ϊ0����ֱ����ȡ�ʱ�临�Ӷ�0(V+E)
		int cur = que.front();
		que.pop();
		res.push_back(cur);

		for (auto& to : grid[cur]) {  // �������Ե�ǰ�ڵ�Ϊ�����յ����ȼ�1
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
		cout << "���ڻ�" << endl;
		return -1;
	}
}

int main() {
	return TopologicalSort();
}