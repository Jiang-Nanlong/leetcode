#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这题是要在给定的candidates数组中找出任意个数，这些数字的和等于target，然后每个数字可以重复使用。
//在剪枝之前，如果当前值已经等于target了，但是遇到比当前值还大的数，显然就大于target了，但是这里还是会进入到下一层递归，这就浪费了时间。
//所以可以先给数组排序，只有当sum加上当前值小于等于target的时候，才会进入递归，如果已经大于了，就不要再走下一层递归了。
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> cb;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());  //搭配剪枝操作
		Helper(candidates, target, 0, 0, cb, res);
		return res;
	}

	void Helper(vector<int>& candidates, int target, int sum, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}
		//if (sum > target) return;  //剪枝以后取消

		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {  //sum + candidates[i] <= target剪枝
			cb.push_back(candidates[i]);
			Helper(candidates, target, sum + candidates[i], i, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<int> candidates{ 2,3,5 };
	vector<vector<int>> res = st.combinationSum(candidates, 8);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}