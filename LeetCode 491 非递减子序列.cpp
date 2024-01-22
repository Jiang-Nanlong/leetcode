#include <iostream>
#include <vector>
using namespace std;

//给定一个整数数组，找出该数组中不同的递增子序列，子序列中至少有两个元素，解集中不能有重复项
//这个题只考虑在树层去重就行

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> cb;
		vector<vector<int>> res;
		Helper(nums, 0, cb, res);
		return res;
	}
	void Helper(vector<int>& nums, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (cb.size() >= 2)
			res.push_back(cb);

		int used[201] = { 0 };  //这里也可以用set，但是题目说nums[i]在-100到100之间，所以可以用数组更快。
		for (int i = startindex; i < nums.size(); i++) {
			if ((!cb.empty() && nums[i] < cb.back()) || (used[100 + nums[i]] == 1))
				continue;
			used[nums[i] + 100] = 1;  //这里的used数组不用回溯，因为他在每一个树枝上都会新创建，只有在树层上才会保持，所以可以只在树层去重
			cb.push_back(nums[i]);
			Helper(nums, i + 1, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<int> nums{ 4,6,7,7 };
	vector<vector<int>> res = st.findSubsequences(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}