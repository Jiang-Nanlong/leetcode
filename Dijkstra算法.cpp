#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
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

int main() {
	Solution st;
	cout << st.dijkstra() << endl;
	return 0;
}