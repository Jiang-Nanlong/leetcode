#include <iostream>
#include <vector>
using namespace std;

//数组中的每个数都不一样，而且nums[i]在-10到10之间，这个题要返回所有数的全排列，
//那么在每个树枝的每一层都得把所有的数都考虑遍，所以for循环从0开始。
//而且这回的去重不是在树层上，而是在树枝上去掉已经使用过的元素，所以使用used数组作为参数，在树枝的每一层使用

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> cb;
		vector<vector<int>> res;
		bool used[21];
		memset(used, false, 21);
		Helper(nums, cb, res, used);
		return res;
	}

	void Helper(vector<int>& nums, vector<int>& cb, vector<vector<int>>& res, bool used[]) {
		if (cb.size() == nums.size()) {
			res.push_back(cb);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[10 + nums[i]] == true) continue;

			used[10 + nums[i]] = true;
			cb.push_back(nums[i]);
			Helper(nums, cb, res, used);
			cb.pop_back();
			used[10 + nums[i]] = false;
		}
	}
};

void main() {
	Solution st;
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> res = st.permute(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}