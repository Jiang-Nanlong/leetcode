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

int main() {
	Solution st;
	vector<vector<int>> edges{ {1, 2},{2, 3},{3, 4},{4, 1},{1, 5} };
	vector<int> res = st.findRedundantDirectedConnection(edges);
	if (res.size() > 0)
		cout << res[0] << "  " << res[1] << endl;
	return 0;
}