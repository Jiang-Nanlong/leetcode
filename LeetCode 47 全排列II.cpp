#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这个题相较于上个题，有一个不同点，就是nums数组中可能有重复数字，解集中不能包含重复解
//其实这么看来他在树枝上的逻辑与46题一样，但是在树层上要去重，一开始没想起来怎么写
//后来看了代码才知道，原来可以用和LeetCode 40 组合总和II的逻辑一样来在树层去重
//这么想，used数组还挺厉害，既可以在树枝上表示哪个已经使用，还可以在树层上去重。

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> cb;
		vector<vector<int>> res;
		vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end());  //需要排序，让相同的数字靠在一起
		Helper(nums, cb, res, used);
		return res;
	}

	void Helper(vector<int>& nums, vector<int>& cb, vector<vector<int>>& res, vector<bool>& used) {
		if (cb.size() == nums.size()) {
			res.push_back(cb);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

			if (used[i] == false) {
				used[i] = true;
				cb.push_back(nums[i]);
				Helper(nums, cb, res, used);
				cb.pop_back();
				used[i] = false;
			}
		}
	}
};

void main() {
	Solution st;
	vector<int> nums{ 1,1,2 };
	vector<vector<int>> res = st.permuteUnique(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}