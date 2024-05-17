#include <iostream>
#include <vector>
using namespace std;

//题意是给定一个二叉树，数中的每条边都是有向边，父节点指向叶节点。然后二叉树中多了一条边，使得二叉树变成了有向图，现在需要找出这条边
//如果有多条边满足题意，返回最后出现的边。
//edges是一个二维数组，edges[i]={u，v}，表示u指向v的一条边

//这个题是真难，我怎么也想不到和并查集有关系。后来看了答案才知道，一个树要变成图，无非两种情况，第一种是树中的某个节点在添加了一条边以后，变成了入度为2的了。
//第二种情况是树中存在一个环。
//入度为2的情况，通过统计每个节点的入度情况，找出连接在入度为2的节点上的边，然后依次删除这些边，判断删除后的图是否构成一个二叉树。判断是否是树可以通过并查集来实现。
//存在环的情况，仅仅使用并查集就行，如果当前边的两个节点都在并查集内，而且这两个节点的根节点一样，那么这条边就是我们要找的，因为这两个节点已经指向同一个根节点了，现在又想用一条边把他俩连起来，那肯定是出错了。
//这个题真难。

class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int inDegree[N] = { 0 };
		n = edges.size();
		for (int i = 0; i < n; i++) {
			inDegree[edges[i][1]]++;
		}
		vector<int> vec;  //记录连接在入度为2的节点上的边在edges数组中的索引
		for (int i = n - 1; i >= 0; i--) {   //因为存在多条边的时候返回最后一条，所以这里逆序遍历，找出两条指向同一个节点的边
			if (inDegree[edges[i][1]] == 2)
				vec.push_back(i);
		}
		if (vec.size() > 0) {
			if (isTreeAfterRemoveEdge(edges, vec[0]))  //先使用不包含vec[0]的边的数组构造并查集，判断是否能构成一棵树
				return edges[vec[0]];
			else
				return edges[vec[1]];
		}

		return getRemoveEdge(edges);  //如果运行到这，说明题目多的那条边不是因为入度为2，而是因为形成了环
	}

private:
	static const int N = 1001; // 节点数
	vector<int> father = vector<int>(N, 0);
	int n; // 边数
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

	bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deleteEdge) {
		init();
		for (int i = 0; i < n; i++) {
			if (i == deleteEdge)   //使用edges数组中除了deleteEdge这条边之外的其他边来构造树，看是否能构造成功
				continue;
			if (isSame(edges[i][0], edges[i][1]))
				return false;
			join(edges[i][0], edges[i][1]);
		}
		return true;
	}

	vector<int> getRemoveEdge(vector<vector<int>>& edges) {   //根据edges数组构造这棵树，看看哪条边中的两个节点在树中已经存在，而且具有相同的根节点，那么结果就是哪条边
		init();
		for (int i = 0; i < n; i++) {
			if (isSame(edges[i][0], edges[i][1]))
				return edges[i];
			join(edges[i][0], edges[i][1]);
		}
		return {};
	}
};

// 第二次做，还是不会，这个题太难了
// 题目的意思是原本是一棵树，然后其中加了一条边就成了图了，现在要找出这条边。如果有两条边可以删除，那么就删除后边出现的那条边
// 答案中讨论了两种情况，一种是图中某个节点的入度为2，那么连接到该节点的两条边肯定有一条是答案；另一种情况是图中有环，这种情况只能用并查集来找。
// 在第一种情况中，删除一条边以后要判断图是否变为一棵树，也是要用并查集来做。

class Solution1 {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int inDegree[N] = { 0 };
		edgesNum = edges.size();
		for (int i = 0; i < edgesNum; i++)
			inDegree[edges[i][1]]++;

		vector<int> vec;
		for (int i = edgesNum - 1; i >= 0; i--) {
			if (inDegree[edges[i][1]] == 2)
				vec.push_back(i);
		}
		if (vec.size() > 0) {
			if (isTreeAfterRemoveEdge(edges, vec[0]))
				return edges[vec[0]];
			else
				return edges[vec[1]];
		}

		return getRemoveEdge(edges);
	}

private:
	static const int N = 1001;
	vector<int> father = vector<int>(N, 0);
	int edgesNum;

	void init() {
		for (int i = 0; i < N; i++)
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

	vector<int> getRemoveEdge(vector<vector<int>>& edges) {  //用来处理图中包含环的情况，一旦找到某条边的节点都已经在并查集中，就返回这条边
		init();
		for (int i = 0; i < edgesNum; i++) {
			if (isSame(edges[i][0], edges[i][1]))
				return edges[i];
			join(edges[i][0], edges[i][1]);
		}
		return {};
	}

	bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deleteEdge) { //判断移除第deleteEdge条边以后，图是否变成了树
		init();
		for (int i = 0; i < edgesNum; i++) {
			if (i == deleteEdge)
				continue;
			if (isSame(edges[i][0], edges[i][1]))
				return false;
			join(edges[i][0], edges[i][1]);
		}
		return true;
	}
};


//第三次做，这回自己做出来了
class Solution2 {
public:
	int n = 1001;
	vector<int> father = vector<int>(n);
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
		father[u] = v;
	}

	bool isATree(vector<vector<int>>& edges, vector<int> edge) {  //判读移除edge这条边以后是不是一棵树
		init();
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i] != edge) {
				if (isSame(edges[i][0], edges[i][1]))
					return false;
				else
					join(edges[i][0], edges[i][1]);
			}
		}
		return true;
	}

	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<int> inDegree = vector<int>(n, 0);
		int node = -1;
		for (int i = 0; i < edges.size(); i++) {  // 统计每个节点的入度
			if (++inDegree[edges[i][1]] == 2)
				node = edges[i][1];
		}

		vector<vector<int>> mayedges;
		if (node != -1) {
			for (int i = edges.size() - 1; i >= 0; i--) {  // 把导致入度为2的两条边都找出来
				if (edges[i][1] == node) {
					mayedges.push_back(edges[i]);
				}
			}
		}

		if (!mayedges.empty()) {  // if条件成立说明有一个节点入度为2
			cout << mayedges[0][0] << "," << mayedges[0][1] << endl;
			cout << mayedges[1][0] << "," << mayedges[1][1] << endl;

			if (isATree(edges, mayedges[0]))  // 分别移除两条边看看剩下的还是不是树
				return mayedges[0];
			else
				return mayedges[1];
		}
		else {  // 说明图中有环
			init();
			for (int i = 0; i < edges.size(); i++) {
				if (isSame(edges[i][0], edges[i][1]))
					return edges[i];
				else
					join(edges[i][0], edges[i][1]);
			}
		}
		return {};
	}
};

int main() {
	Solution st;
	vector<vector<int>> edges{ {1, 2},{2, 3},{3, 4},{4, 1},{1, 5} };
	vector<int> res = st.findRedundantDirectedConnection(edges);
	if (res.size() > 0)
		cout << res[0] << "  " << res[1] << endl;
	cout << "-----------" << endl;

	Solution1 st1;
	vector<int> res1 = st1.findRedundantDirectedConnection(edges);
	if (res1.size() > 0)
		cout << res1[0] << "  " << res1[1] << endl;

	cout << "-----------" << endl;
	Solution2 st2;
	vector<int> res2 = st2.findRedundantDirectedConnection(edges);
	if (res2.size() > 0)
		cout << res2[0] << "  " << res2[1] << endl;
	return 0;
}