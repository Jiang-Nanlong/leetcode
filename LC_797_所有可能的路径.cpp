#include <iostream>
#include <vector>
using namespace std;

//����һ�������޻�ͼ���ҳ�0����n-1���ڵ������·��
//��dfs����ʵ����һ���򵥵Ļ�����

class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> res;
		vector<int> path;
		path.push_back(0);
		backtrace(graph, res, path, 0);
		return res;
	}
	void backtrace(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int n) {
		if (n == graph.size() - 1) {
			res.push_back(path);
			return;
		}

		for (int i = 0; i < graph[n].size(); i++) {
			path.push_back(graph[n][i]);
			backtrace(graph, res, path, graph[n][i]);
			path.pop_back();
		}
	}

	//�ڶ�����
	vector<vector<int>> res;
	vector<int> path;
	vector<vector<int>> allPathsSourceTarget1(vector<vector<int>>& graph) {
		path.push_back(0);
		dfs(graph, 0);
		return res;
	}
	void dfs(vector<vector<int>>& graph, int n) {
		if (n == graph.size() - 1) {
			res.push_back(path);
			return;
		}
		for (int i = 0; i < graph[n].size(); i++) {
			path.push_back(graph[n][i]);
			dfs(graph, graph[n][i]);
			path.pop_back();
		}
	}
};

int main() {
	Solution st;
	vector<vector<int>> graph{ {1,2},{3},{3},{} };
	vector<vector<int>>res = st.allPathsSourceTarget(graph);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	vector<vector<int>>res1 = st.allPathsSourceTarget(graph);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[i].size(); j++) {
			cout << res1[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}