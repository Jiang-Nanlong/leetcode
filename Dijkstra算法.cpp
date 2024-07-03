#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int dijkstra() {
		int n, m;  // n���ڵ㣬m����
		int p1, p2, val;  // p1->p2��Ȩ��val

		cin >> n >> m;
		vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));   // �ڽӾ����ʾͼ
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> val;
			grid[p1][p2] = val;
		}

		vector<int> minDist(n + 1, INT_MAX);
		vector<int> visited(n + 1, false);

		int start = 1, end = n;
		minDist[start] = 0;
		
		for (int i = 1; i <= n; i++) {   // ����n�֣���Ϊÿһ�ֻ��һ���ڵ���ɷ��ʵļ���
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
					// �о������!visited������û�ж����ԣ���ΪȨ�ض�������
					// ��ô��v������лص�֮ǰ��·������ô����·���϶��ǳ���ԭ����·����
					// ����������������ͬʱȨ���и���ʱ���ͻ������ѭ��������dijkstra�㷨ֻ�ܴ���Ȩ�ض������������⣬�����ܳ��ָ�����
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