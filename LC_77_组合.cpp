#include <iostream>
#include <vector>
using namespace std;

//给定两个整数n和k，返回[1,n]中所有可能的k个数的组合

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> cb;
		vector<vector<int>> res;
		Helper(n, k, 1, cb, res);
		return res;
	}
	void Helper(int n, int k, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (cb.size() == k) {
			res.push_back(cb);
			return;
		}

		for (int i = startindex; i <= n; i++) {  //这个地方可以再优化一下，
			//比如说要找到5个数的组合，但是从startindex到数组结束已经不够五个数了，那么这一段就可以剪枝了
			//可以把i <= n，换成i<=n-(k-cb.size())+1
			cb.push_back(i);
			Helper(n, k, i + 1, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<vector<int>> res = st.combine(4, 2);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << "  ";
		cout << endl;
	}
}
