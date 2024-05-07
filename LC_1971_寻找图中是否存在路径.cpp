#include <iostream>
#include <vector>
using namespace std;

//����һ����ά����edges��edges[i]={u,v}��ʾ�ڵ�u�ͽڵ�v֮�����һ���ߣ�������˫��ߣ�����ÿ������û��ָ������ı�
//����source��destination֮���Ƿ����·��
//��������ò��鼯��

class Solution {
public:
	//�±������һ��ʼ��д�Ĵ��룬���ǲ��У���Ϊһ��ʼ����Ϊedges[i]���Ǵ�i������һ���ߣ���������˳��������һֱ����ȥ�����������˲����ײ���������edges��������Ǵ�����бߡ�
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

//�ڶ�����
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