#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//给定一个candidates数组，找出数组中和为target的组合。这个题和LeetCode 39不一样的地方在于数组中可能有重复的数，但是解集中不能包含重复组合
//回溯解决的问题都可以抽象成树形结构。
//这个题就面临着去重的问题，一个解中可以包含重复元素，但是解集中不能包含重复解，所以这里的去重是在树层去重，而不是在树枝去重。


class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> cb;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		Helper(candidates, target, 0, 0, cb, res);
		return res;
	}

	void Helper(vector<int>& candidates, int target, int sum, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}

		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			if (i > startindex && candidates[i] == candidates[i - 1]) continue;   //这一行我开始把i>startindex写成i>0了，如果写成i>0的话，就会跳过所有一样的数，在树层和树枝之间都去掉了。
			//这个树层去重是这个题的关键。
			cb.push_back(candidates[i]);
			Helper(candidates, target, sum + candidates[i], i + 1, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<int> candidates{ 10,1,2,7,6,1,5 };
	int target = 8;
	vector<vector<int>> res = st.combinationSum2(candidates, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}