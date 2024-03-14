#include <iostream>
#include <vector>
using namespace std;

//����һ��ͼ�����ͼ�Ƕ����������һ�����γɵģ��л���ͼ������Ҫ�ҳ������ߣ������ͼ���±����
//��Ϊ��һ��ͼ��ɵģ�����Ӧ�ö���һ�������ĸ��ڵ㣬��ͷ��ʼ�������еıߣ������һ���ߵ������ڵ�ĸ��ڵ���ͬ��˵�������ߵ������ڵ㶼�Ѿ��������ˣ������ʱ�ٰ������ڵ��������ͻ��γɻ���

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		init();
		for (int i = 0; i < edges.size(); i++) {
			if (isSame(edges[i][0], edges[i][1])) {
				return edges[i];
			}
			else
				join(edges[i][0], edges[i][1]);
		}
		return {};
	}
private:
	int n = 1001;
	vector<int> father = vector<int>(n, 0);
	void init() {
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}
	}

	int find(int u) {
		return u == father[u] ? u : father[u] = find(father[u]);
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		father[v] = u;
	}
	bool isSame(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
};

int main() {
	Solution st;
	vector<vector<int>> edges = { {1, 2},{2, 3},{3, 4},{1, 4},{1, 5} };
	vector<int> res = st.findRedundantConnection(edges);
	if (!res.empty()) {
		for (int i : res)
			cout << i << "  ";
	}
	return 0;
}