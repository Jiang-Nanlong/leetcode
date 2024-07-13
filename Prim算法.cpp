#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// prime�㷨��ʱ�临�Ӷ���O(n^2)��ֻ�ͽڵ������йأ��ͱߵ������޹أ�����ʺϳ���ͼ
// ��������д�������ذ��kruskal�㷨����һģһ�������˴���minDist���߼��ϲ�һ��

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

		for (int i = 1; i < v; i++) {   // v-1����
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

	// ʹ�ö��Ż��汾��Ҳ�ǳ���minDist�Ĵ����߼��⣬����Ķ���kruskalһģһ��
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

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // pq�е�pair<int,int>��first�ǵ��ڵ�ľ��룬second���ǽڵ�ֵ����������ʹ��greater<>��
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