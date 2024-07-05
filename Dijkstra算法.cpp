#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution1 {
public:
	// 这种dijkstra算法的时间复杂度是O(n^2)，和节点数量有关，和边的数量无关，因此适用于稠密图
	// 所以这种情况下适合用邻接矩阵表示图
	int dijkstra() {
		int n, m;  // n个节点，m条边
		int p1, p2, val;  // p1->p2，权重val

		cin >> n >> m;
		vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));   // 邻接矩阵表示图
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> val;
			grid[p1][p2] = val;
		}

		vector<int> minDist(n + 1, INT_MAX);
		vector<int> visited(n + 1, false);

		int start = 1, end = n;
		minDist[start] = 0;
		
		for (int i = 1; i <= n; i++) {   // 遍历n轮，因为每一轮会加一个节点进可访问的集合
			int minval = INT_MAX;
			int v = 1;
			for (int j = 1; j <= n; j++) {
				if (!visited[j] && minDist[j] < minval) {
					minval = minDist[j];
					v = j;
				}
			}
			visited[v] = true;
			for (int i = 1; i <= n; i++) {
				if (!visited[i] && grid[v][i] != INT_MAX && minval + grid[v][i] < minDist[i]) {  
					// 感觉这里的!visited条件有没有都可以，因为权重都是整数
					// 那么从v点如果有回到之前的路径，那么这条路径肯定是长于原来的路径的
					// 如果不加这个条件，同时权重有负数时，就会出现死循环，但是dijkstra算法只能处理权重都是整数的问题，不可能出现负数啊
					minDist[i] = minval + grid[v][i];
				}
			}

		}
		if (minDist[end] == INT_MAX) {
			cout << "can't arrive at destination" << endl;
			return -1;
		}
		else
			return minDist[end];
	}
};

class Solution2 {
private:
	class mycomparison
	{
	public:
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
			return a.second > b.second;
		}
	};
	struct Edge
	{
		int to;
		int val;
		Edge(int t,int w):to(t),val(w){}
	};
public:
	int dijkstra() {
		int n, m;
		int p1, p2, val;
		cin >> n >> m;

		vector<list<Edge>> grid(n + 1);  // 邻接表法表示图
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> val;
			grid[p1].push_back(Edge(p2, val));
		}

		int start = 1;
		int end = n;

		vector<int> minDist(n + 1, INT_MAX);
		vector<bool> visited(n + 1, false);

		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;  // 小顶堆只用来弹出到达源点最近的边，时间复杂度是O(logE)
		pq.emplace(pair<int, int>(start, 0));

		minDist[start] = 0;

		while (!pq.empty()) {  // 每条边都遍历一次，时间复杂度是O(E)，所以整个代码的时间复杂度是O(ElogE)
			pair<int, int> cur = pq.top();
			pq.pop();
			if (visited[cur.first]) continue;
			// 这个地方挺重要，因为就按代码随想录的例子来说，把1加入小顶堆以后，会更新2和3的minDist，同时会把它俩都加入小顶堆。接下来在2和3中选择一个节点作为下一个节点，会选择2。
			// 在选择2以后又会更新3,4,6的minDist，同时又都会加入到小顶堆，这时候小顶堆里就有两个节点3对应的最短路径了。下一次选择最短路径会选择3（从2过来的这条路径），然后会更新4的最短路径。
			// 下一次再选择节点时，节点3（从1过来的那条路径）就是最短的，又会再选择一次3，而此时3已经被标记为visited的了。
			// 也就是说，堆中可能同时存在一个节点的好几个路径长度。

			visited[cur.first] = true;
			for (Edge edge : grid[cur.first]) {
				if (!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]) {  // 这里的minDist[cur.first]可以直接换成cur.second吗？
					// 有没有可能一个点已经被加入到小顶堆了，但是还没有弹出，然后当前节点又直接连接到这个点，且更近
					minDist[edge.to] = minDist[cur.first] + edge.val;
					pq.emplace(pair<int, int>(edge.to, minDist[edge.to]));  // 这个地方是，只要一个节点的最短路径发生变化就把它加入到小顶堆中。
				}
			}
		}
		if (minDist[end] == INT_MAX) {
			cout << "can't arrive at destination" << endl;
			return -1;
		}
		else
			return minDist[end];
	}
};

int main() {
	/*Solution1 st1;
	cout << st1.dijkstra() << endl;*/
	Solution2 st2;
	cout << st2.dijkstra() << endl;
	return 0;
}