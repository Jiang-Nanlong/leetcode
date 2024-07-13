#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// prime算法的时间复杂度是O(n^2)，只和节点数量有关，和边的数量无关，因此适合稠密图
// 这个代码的写法和朴素版的kruskal算法几乎一模一样，除了处理minDist的逻辑上不一样

class Solution {
public:
	int prim() {
		int v, e;
		int x, y, val;
		cin >> v >> e;
		vector<vector<int>> grid(1 + v, vector<int>(1 + v, 10001));
		while (e--) {
			cin >> x >> y >> val;
			grid[x][y] = val;
			grid[y][x] = val;
		}
		vector<int> minDist(1 + v, 10001);
		vector<bool> isvisited(1 + v, false);

		for (int i = 1; i < v; i++) {   // v-1条边
			int cur = -1;
			int minVal = INT_MAX;
			for (int j = 1; j <= v; j++) {
				if (!isvisited[j] && minDist[j] < minVal) {
					cur = j;
					minVal = minDist[j];
				}
			}

			isvisited[cur] = true;
			for (int j = 1; j <= v; j++) {
				if (!isvisited[j] && grid[cur][j] < minDist[j]) {
					minDist[j] = grid[cur][j];
				}
			}
		}

		int res = 0;
		for (int i = 2; i <= v; i++) {
			res += minDist[i];
		}
		return res;
	}

	// 使用堆优化版本，也是除了minDist的处理逻辑外，其余的都和kruskal一模一样
	int prim1() {
		int v, e;
		int x, y, val;
		cin >> v >> e;
		vector<list<pair<int, int>>> grid(1 + v);

		while (e--) {
			cin >> x >> y >> val;
			grid[x].push_back({ y,val });
			grid[y].push_back({ x,val });
		}
		vector<int> minDist(1 + v, 10001);
		vector<bool> isvisited(1 + v, false);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // pq中的pair<int,int>的first是到节点的距离，second才是节点值，这样就能使用greater<>了
		pq.emplace(pair<int, int>(0, 1));
		minDist[1] = 0;

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			if (isvisited[cur.second]) continue;

			isvisited[cur.second] == true;
			for (auto edge : grid[cur.second]) {
				if (!isvisited[edge.first] && minDist[edge.first] > edge.second) {
					minDist[edge.first] = edge.second;
					pq.emplace(pair<int, int>(edge.second, edge.first));
				}
			}
		}

		int res = 0;
		for (int i = 1; i <= v; i++) {
			cout << minDist[i] << " ";
			res += minDist[i];
		}
		return res;
	}
};
int main() {
	Solution st;
	cout << st.prim1() << endl;
	return 0;
}