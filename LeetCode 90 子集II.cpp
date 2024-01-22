#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这个题和LeetCode 78 子集有一点不一样，这个题的nums数组中可能有重复元素，但是解集中不能包含重复解

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<int> cb;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		Helper(nums, 0, cb, res);
		return res;
	}
	void Helper(vector<int>& nums, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		res.push_back(cb);
		for (int i = startindex; i < nums.size(); i++) {
			if (i > startindex && nums[i] == nums[i - 1]) continue;   //树层跳过重复解
			//这个地方跟LeetCode 40 组合总和II里的一样
			cb.push_back(nums[i]);
			Helper(nums, i + 1, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> res = st.subsetsWithDup(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j];
		cout << endl;
	}
}