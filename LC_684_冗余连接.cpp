#include <iostream>
#include <vector>
using namespace std;

//给定一个图，这个图是二叉树中添加一条边形成的，有环的图，现在要找出这条边，让这个图重新变回树
//因为是一个图变成的，所以应该都有一个公共的根节点，从头开始遍历所有的边，如果有一条边的两个节点的根节点相同，说明这条边的两个节点都已经在树里了，如果此时再把两个节点连起来就会形成环。

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		init();
		for (int i = 0; i < edges.size(); i++) {
			if (isSame(edges[i][0], edges[i][1])) {
				return edges[i];
			}
			else
				join(edges[i][0], edges[i][1]);
		}
		return {};
	}
private:
	int n = 1001;
	vector<int> father = vector<int>(n, 0);
	void init() {
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}
	}

	int find(int u) {
		return u == father[u] ? u : father[u] = find(father[u]);
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		father[v] = u;
	}
	bool isSame(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
};

//第二次做
class Solution1 {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> res;
		init();
		for (int i = 0; i < edges.size(); i++) {
			if (isSame(edges[i][0], edges[i][1]))
				res = edges[i];
			else
				join(edges[i][0], edges[i][1]);
		}
		return res;
	}

	int n = 1001;
	vector<int> father = vector<int>(n, 0);
	void init() {
		for (int i = 0; i < n; i++)
			father[i] = i;
	}
	int find(int u) { return u == father[u] ? u : father[u] = find(father[u]); }
	bool isSame(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v)
			return;
		father[v] = u;
	}
};

// 第三次做
class Solution2 {
public:
	int n = 1001;
	vector<int> father = vector<int>(n);
	void init() {
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}
	}
	int find(int u) { return u == father[u] ? u : father[u] = find(father[u]); }
	bool isSame(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v)
			return;
		father[v] = u;
	}

	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		init();
		for (int i = 0; i < edges.size(); i++) {
			if (isSame(edges[i][0], edges[i][1]))
				return edges[i];
			else
				join(edges[i][0], edges[i][1]);
		}
		return {};
	}
};

int main() {
	Solution st;
	vector<vector<int>> edges = { {1, 2},{2, 3},{3, 4},{1, 4},{1, 5} };
	vector<int> res = st.findRedundantConnection(edges);
	if (!res.empty()) {
		for (int i : res)
			cout << i << "  ";
	}
	cout << endl;
	cout << "------------------" << endl;

	Solution1 st1;
	vector<int> res1 = st1.findRedundantConnection(edges);
	if (!res1.empty()) {
		for (int i : res1)
			cout << i << "  ";
	}
	cout << endl;
	cout << "------------------" << endl;

	Solution2 st2;
	vector<int> res2 = st2.findRedundantConnection(edges);
	if (!res2.empty()) {
		for (int i : res2)
			cout << i << "  ";
	}
	return 0;
}