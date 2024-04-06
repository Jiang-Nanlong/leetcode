#include <iostream>
#include <vector>
using namespace std;

//在1-9之间选择k个数，相加总和为n

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> cb;
		vector<vector<int>> res;
		Helper(k, n, 1, 0, cb, res);
		return res;
	}
	void Helper(int k, int n, int startindex, long long sum, vector<int>& cb, vector<vector<int>>& res) {
		if (sum > n) return;  //剪枝操作

		if (cb.size() == k) {  //这里不能把两个条件写到一起，如果写到一起，即便是当元素数量等于k时，但是sum!=n，那么程序也不会return，就会超时
			if (sum == n) res.push_back(cb);
			return;
		}

		for (int i = startindex; i <= 9 - (k - cb.size()) + 1; i++) {   //i<= 9 - (k - cb.size()) + 1 剪枝操作
			cb.push_back(i);
			Helper(k, n, i + 1, sum + i, cb, res);  //之间传参sum+i，从而避免sum回溯，只对cb进行回溯
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<vector<int>> res = st.combinationSum3(3, 7);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}
