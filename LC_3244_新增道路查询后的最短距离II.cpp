#include <iostream>
#include <vector>
#include <set>
using namespace std;

// ����n���ڵ㣬����д�i��i+1��·����������ÿ��·�����ȶ�Ϊ1��Ȼ�����һ��queries���飬�����е�ÿһ��Ԫ�ش�������ӵ�һ��·����
// ����һ�����飬�����е�ÿһλ���������һ����·���󣬵�0���ڵ㵽��n-1���ڵ��·�����ȡ�
// ���������һ����Ҫ����Ϣ����i!=jʱ��������queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]��
// Ҳ����˵������������ӵ�·��֮�䶼�ǰ����ͱ����������������ڵĹ�ϵ�������ڽ����ϵ��

// ԭ���������ô�򵥣�������ʱ�������Ҫ��dijkstra�㷨��

class Solution {
public:
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		set<pair<int, int>> st;
		for (int i = 0; i < n - 1; i++)   // ���������·��
			st.insert({ i, i + 1 });

		vector<int> res;
		for (auto& v : queries) {
			int l = v[0], r = v[1];

			// ��ôд�еĲ��������ᳬʱ����lower_bound�Ͳ���
			/*auto it = st.begin();
			while (it!=st.end() && *it < pair<int, int>(l, -1))
				it++;*/
			
			// �ҳ���һ�������ڵ��������·����·����Ȼ�����ж��������ҵ���·���ǲ��Ǳ�����ӵ�·��������
			auto it = st.lower_bound(pair<int, int>(l, -1));
			if (it != st.end() && it->first >= l && it->second <= r) {  // ����ҳ�����·��ȷʵ�Ǳ���·�������ˣ���ɾ��ԭ����·��������·������
				while (it != st.end() && it->first >= l && it->second <= r) {
					it = st.erase(it);
				}
				st.insert({ l, r });
			}
			res.push_back(st.size());
		}
		return res;
	}
};

int main() {
	Solution st;
	int n = 6;
	vector<vector<int>> queries{ {1,5},{3,5} };
	vector<int> res = st.shortestDistanceAfterQueries(n, queries);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}