#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int n, int k) {
		vector<int> cur;
		vector<vector<int>> res;
		dfs(n, k, 1, 0,cur, res);
		return res;
	}
private:
	void dfs(int n, int k, int i,int sum, vector<int>& cur, vector<vector<int>>& res) {
		if (cur.size() == k ) {
			if (sum == n)
				res.push_back(cur);
			return;
		}
		for (int j = i; j <= 9-(k-cur.size())+1; j++) {
			cur.push_back(j);
			dfs(n, k, j + 1, sum + j, cur, res);
			cur.pop_back();
		}
	}
};

int main() {
	Solution s;
	vector<int> cur;
	vector<vector<int>> res = s.combinationSum3(7, 3);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	return 0;
}