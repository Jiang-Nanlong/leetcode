#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution1 {
public:
	// ����dijkstra�㷨��ʱ�临�Ӷ���O(n^2)���ͽڵ������йأ��ͱߵ������޹أ���������ڳ���ͼ
	// ��������������ʺ����ڽӾ����ʾͼ
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

		vector<list<Edge>> grid(n + 1);  // �ڽӱ���ʾͼ
		for (int i = 0; i < m; i++) {
			cin >> p1 >> p2 >> val;
			grid[p1].push_back(Edge(p2, val));
		}

		int start = 1;
		int end = n;

		vector<int> minDist(n + 1, INT_MAX);
		vector<bool> visited(n + 1, false);

		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;  // С����ֻ������������Դ������ıߣ�ʱ�临�Ӷ���O(logE)
		pq.emplace(pair<int, int>(start, 0));

		minDist[start] = 0;

		while (!pq.empty()) {  // ÿ���߶�����һ�Σ�ʱ�临�Ӷ���O(E)���������������ʱ�临�Ӷ���O(ElogE)
			pair<int, int> cur = pq.top();
			pq.pop();
			if (visited[cur.first]) continue;
			// ����ط�ͦ��Ҫ����Ϊ�Ͱ���������¼��������˵����1����С�����Ժ󣬻����2��3��minDist��ͬʱ�������������С���ѡ���������2��3��ѡ��һ���ڵ���Ϊ��һ���ڵ㣬��ѡ��2��
			// ��ѡ��2�Ժ��ֻ����3,4,6��minDist��ͬʱ�ֶ�����뵽С���ѣ���ʱ��С��������������ڵ�3��Ӧ�����·���ˡ���һ��ѡ�����·����ѡ��3����2����������·������Ȼ������4�����·����
			// ��һ����ѡ��ڵ�ʱ���ڵ�3����1����������·����������̵ģ��ֻ���ѡ��һ��3������ʱ3�Ѿ������Ϊvisited���ˡ�
			// Ҳ����˵�����п���ͬʱ����һ���ڵ�ĺü���·�����ȡ�

			visited[cur.first] = true;
			for (Edge edge : grid[cur.first]) {
				if (!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]) {  // �����minDist[cur.first]����ֱ�ӻ���cur.second��
					// ��û�п���һ�����Ѿ������뵽С�����ˣ����ǻ�û�е�����Ȼ��ǰ�ڵ���ֱ�����ӵ�����㣬�Ҹ���
					minDist[edge.to] = minDist[cur.first] + edge.val;
					pq.emplace(pair<int, int>(edge.to, minDist[edge.to]));  // ����ط��ǣ�ֻҪһ���ڵ�����·�������仯�Ͱ������뵽С�����С�
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