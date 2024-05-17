#include <iostream>
#include <vector>
using namespace std;

//�����Ǹ���һ�������������е�ÿ���߶�������ߣ����ڵ�ָ��Ҷ�ڵ㡣Ȼ��������ж���һ���ߣ�ʹ�ö��������������ͼ��������Ҫ�ҳ�������
//����ж������������⣬���������ֵıߡ�
//edges��һ����ά���飬edges[i]={u��v}����ʾuָ��v��һ����

//����������ѣ�����ôҲ�벻���Ͳ��鼯�й�ϵ���������˴𰸲�֪����һ����Ҫ���ͼ���޷������������һ�������е�ĳ���ڵ��������һ�����Ժ󣬱�������Ϊ2���ˡ�
//�ڶ�����������д���һ������
//���Ϊ2�������ͨ��ͳ��ÿ���ڵ�����������ҳ����������Ϊ2�Ľڵ��ϵıߣ�Ȼ������ɾ����Щ�ߣ��ж�ɾ�����ͼ�Ƿ񹹳�һ�����������ж��Ƿ���������ͨ�����鼯��ʵ�֡�
//���ڻ������������ʹ�ò��鼯���У������ǰ�ߵ������ڵ㶼�ڲ��鼯�ڣ������������ڵ�ĸ��ڵ�һ������ô�����߾�������Ҫ�ҵģ���Ϊ�������ڵ��Ѿ�ָ��ͬһ�����ڵ��ˣ�����������һ���߰��������������ǿ϶��ǳ����ˡ�
//��������ѡ�

class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int inDegree[N] = { 0 };
		n = edges.size();
		for (int i = 0; i < n; i++) {
			inDegree[edges[i][1]]++;
		}
		vector<int> vec;  //��¼���������Ϊ2�Ľڵ��ϵı���edges�����е�����
		for (int i = n - 1; i >= 0; i--) {   //��Ϊ���ڶ����ߵ�ʱ�򷵻����һ����������������������ҳ�����ָ��ͬһ���ڵ�ı�
			if (inDegree[edges[i][1]] == 2)
				vec.push_back(i);
		}
		if (vec.size() > 0) {
			if (isTreeAfterRemoveEdge(edges, vec[0]))  //��ʹ�ò�����vec[0]�ıߵ����鹹�첢�鼯���ж��Ƿ��ܹ���һ����
				return edges[vec[0]];
			else
				return edges[vec[1]];
		}

		return getRemoveEdge(edges);  //������е��⣬˵����Ŀ��������߲�����Ϊ���Ϊ2��������Ϊ�γ��˻�
	}

private:
	static const int N = 1001; // �ڵ���
	vector<int> father = vector<int>(N, 0);
	int n; // ����
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
			if (i == deleteEdge)   //ʹ��edges�����г���deleteEdge������֮����������������������Ƿ��ܹ���ɹ�
				continue;
			if (isSame(edges[i][0], edges[i][1]))
				return false;
			join(edges[i][0], edges[i][1]);
		}
		return true;
	}

	vector<int> getRemoveEdge(vector<vector<int>>& edges) {   //����edges���鹹��������������������е������ڵ��������Ѿ����ڣ����Ҿ�����ͬ�ĸ��ڵ㣬��ô�������������
		init();
		for (int i = 0; i < n; i++) {
			if (isSame(edges[i][0], edges[i][1]))
				return edges[i];
			join(edges[i][0], edges[i][1]);
		}
		return {};
	}
};

// �ڶ����������ǲ��ᣬ�����̫����
// ��Ŀ����˼��ԭ����һ������Ȼ�����м���һ���߾ͳ���ͼ�ˣ�����Ҫ�ҳ������ߡ�����������߿���ɾ������ô��ɾ����߳��ֵ�������
// �������������������һ����ͼ��ĳ���ڵ�����Ϊ2����ô���ӵ��ýڵ�������߿϶���һ���Ǵ𰸣���һ�������ͼ���л����������ֻ���ò��鼯���ҡ�
// �ڵ�һ������У�ɾ��һ�����Ժ�Ҫ�ж�ͼ�Ƿ��Ϊһ������Ҳ��Ҫ�ò��鼯������

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

	vector<int> getRemoveEdge(vector<vector<int>>& edges) {  //��������ͼ�а������������һ���ҵ�ĳ���ߵĽڵ㶼�Ѿ��ڲ��鼯�У��ͷ���������
		init();
		for (int i = 0; i < edgesNum; i++) {
			if (isSame(edges[i][0], edges[i][1]))
				return edges[i];
			join(edges[i][0], edges[i][1]);
		}
		return {};
	}

	bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deleteEdge) { //�ж��Ƴ���deleteEdge�����Ժ�ͼ�Ƿ�������
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


//��������������Լ���������
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

	bool isATree(vector<vector<int>>& edges, vector<int> edge) {  //�ж��Ƴ�edge�������Ժ��ǲ���һ����
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
		for (int i = 0; i < edges.size(); i++) {  // ͳ��ÿ���ڵ�����
			if (++inDegree[edges[i][1]] == 2)
				node = edges[i][1];
		}

		vector<vector<int>> mayedges;
		if (node != -1) {
			for (int i = edges.size() - 1; i >= 0; i--) {  // �ѵ������Ϊ2�������߶��ҳ���
				if (edges[i][1] == node) {
					mayedges.push_back(edges[i]);
				}
			}
		}

		if (!mayedges.empty()) {  // if��������˵����һ���ڵ����Ϊ2
			cout << mayedges[0][0] << "," << mayedges[0][1] << endl;
			cout << mayedges[1][0] << "," << mayedges[1][1] << endl;

			if (isATree(edges, mayedges[0]))  // �ֱ��Ƴ������߿���ʣ�µĻ��ǲ�����
				return mayedges[0];
			else
				return mayedges[1];
		}
		else {  // ˵��ͼ���л�
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