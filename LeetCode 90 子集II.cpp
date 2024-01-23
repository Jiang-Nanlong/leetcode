#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
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

	//还可以使用used数组去重
	void Helper1(vector<int>& nums, int startindex, vector<int>& cb, vector<vector<int>>& res, vector<bool>& used) {
		res.push_back(cb);
		for (int i = startindex; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
			used[i] = true;
			cb.push_back(nums[i]);
			Helper1(nums, i + 1, cb, res, used);
			cb.pop_back();
			used[i] = false;
		}
	}

	//还可以模仿LeetCode 491 非递减子序列，在每一层创建一个unordered_set来在层内去重
	void Helper2(vector<int>& nums, int startIndex, vector<int>& cb, vector<vector<int>>& res) {
		res.push_back(cb);
		unordered_set<int> uset;
		for (int i = startIndex; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end()) {
				continue;
			}
			uset.insert(nums[i]);  //因为只在每一层维持这个uset数组，所以不用给它回溯就行
			cb.push_back(nums[i]);
			Helper2(nums, i + 1, cb, res);
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