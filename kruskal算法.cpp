#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��С������kruskal�㷨���Ȱ����еı߰�Ȩֵ��С������������ѡ��ߣ��жϱߵ������˵��Ƿ񶼼�������С�������ļ����У�
// ����Ѿ��������ˣ�˵���л�������֮ǰ�Ѿ��б����������������ˣ����Բ��ùܵ�ǰ�����ߡ����������һ����û���뵽�����У���������߼��뵽��С�������С�
// �����һ���ص�����жϱ��ϵ������ǲ����Ѿ��ڼ������ˣ������ò��鼯��
// ʱ�临�Ӷ��� nlogn�����ţ�+logn�����鼯�������������Ȼ�� nlogn�� nΪ�ߵ�����
// ����kruskal�㷨ʱ�临�ӶȽ��ͱߵ���Ŀ�й�ϵ�������ʺ�ϡ��ͼ��

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