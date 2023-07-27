#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> cur;
		vector<vector<int>> res;
		dfs(n, k, 1, cur, res);
		return res;
	}

private:
	void dfs(int n, int k, int i, vector<int>& cur, vector<vector<int>>& res) {
		if (cur.size() == k) {
			res.push_back(cur);
			return;
		}

		for (int j = i; j <= n - (k - cur.size()) + 1; j++) {   //¼ôÖ¦
			cur.push_back(j);
			dfs(n, k, j + 1, cur, res);
			cur.pop_back();
		}
	}
};

int main() {
	Solution s;
	vector<vector<int>> res;
	res = s.combine(4, 2);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	return 0;
}