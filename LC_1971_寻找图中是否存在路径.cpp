#include <iostream>
#include <vector>
using namespace std;

//给定一个二维数组edges，edges[i]={u,v}表示节点u和节点v之间存在一条边，而且是双向边，而且每个顶点没有指向自身的边
//返回source和destination之间是否存在路径
//这个题是用并查集做

class Solution {
public:
	//下边这个是一开始我写的代码，但是不行，因为一开始我以为edges[i]就是从i引出的一条边，这样就能顺着这条边一直找下去，后来出错了才明白不是这样。edges数组里就是存的所有边。
	/*bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		int begin = source;
		for (int i = 0; i < edges.size(); i++) {
			if (edges[begin][1] == destination)
				return true;
			else {
				begin = edges[begin][1];
			}
		}
		return false;
	}*/

	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		init();
		for (int i = 0; i < edges.size(); i++) {
			join(edges[i][0], edges[i][1]);
		}
		return isSame(source, destination);
	}

private:
	int n = 200005;
	vector<int> father = vector<int>(n, 0);

	void init() {
		for (int i = 0; i < n; ++i) {
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
};

//第二次做
class Solution1 {
public:
	bool validPath(int n, vector<vector<int>>& edges, int source,
		int destination) {
		init();
		for (int i = 0; i < edges.size(); i++)
			join(edges[i][0], edges[i][1]);

		return isSame(source, destination);
	}

	int n = 200001;
	vector<int> father = vector<int>(n, 0);
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
};
int main() {
	Solution st;
	vector<vector<int>> edges{ {0, 1},{0, 2},{3, 5},{5, 4},{4, 3} };
	cout << boolalpha << st.validPath(6, edges, 0, 5) << noboolalpha << endl;
	Solution1 st1;
	cout << boolalpha << st1.validPath(6, edges, 0, 5) << noboolalpha << endl;
	return 0;
}