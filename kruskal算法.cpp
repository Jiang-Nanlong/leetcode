#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最小生成树kruskal算法，先把所有的边按权值从小到大排序，依次选择边，判断边的两个端点是否都加入了最小生成树的集合中，
// 如果已经都加入了，说明有环，在这之前已经有边连接这两个顶点了，所以不用管当前这条边。如果至少有一个点没加入到集合中，则把这条边加入到最小生成树中。
// 这里的一个重点就是判断边上的两点是不是已经在集合中了，可以用并查集。
// 时间复杂度是 nlogn（快排）+logn（并查集），所以最后依然是 nlogn。 n为边的数量
// 所以kruskal算法时间复杂度仅和边的数目有关系，所以适合稀疏图。

struct edge {
	int i, j;
	int val;
	edge(int i,int j,int val):i(i),j(j),val(val){}
};

int n = 1001;
vector<int> father(n);
void init() {
	for (int i = 0; i < n; i++)
		father[i] = i;
}
int find(int u) {
	return u == father[u] ? u : father[u] = find(father[u]);
}
void join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v)
		father[v] = u;
}

bool isSame(int u, int v) {
	u = find(u);
	v = find(v);
	return u == v;
}

class Solution {
public:
	vector<edge> path;
	int kruskal() {
		int v, e;
		int i, j, val;
		cin >> v >> e;
		vector<edge> edges;
		while (e--) {
			cin >> i >> j >> val;
			edges.emplace_back(i, j, val);
		}
		
		sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
			return a.val < b.val;
			});

		init();

		int res = 0;
		path.clear();
		for (auto& edge : edges) {
			if (!isSame(edge.i, edge.j)) {
				path.push_back(edge);
				res += edge.val;
				join(edge.i, edge.j);
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	cout << st.kruskal() << endl;
	for (auto& e : st.path) {
		cout << e.i << "->" << e.j << " : " << e.val << endl;
	}
	return 0;
}