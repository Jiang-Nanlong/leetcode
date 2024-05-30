#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
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

	//使用used数组来去重
	void Helper1(vector<int>& candidates, int target, int sum, int startindex, vector<bool>& used, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}

		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
				//used用来在树层去重，如果在树层中，当前节点的值和上一个值一样，那么used[i-1]==false，因为上一个节点已经回溯回来了，
				//只有当在树枝上时，used[i-1]才会是true
				//used[i-1]==false是在树层去重，used[i-1]==true是在树枝去重，有些问题使用树层去重和树枝去重都能做，但是树层去重的效率会更高一些。
				continue;
			cb.push_back(candidates[i]);
			used[i] = true;
			Helper1(candidates, target, sum + candidates[i], i + 1, used, cb, res);
			used[i] = false;
			cb.pop_back();
		}
	}
	vector<vector<int>> combinationSum21(vector<int>& candidates, int target) {
		vector<int> cb;
		vector<vector<int>> res;
		vector<bool> used(candidates.size(), false);
		sort(candidates.begin(), candidates.end());
		Helper1(candidates, target, 0, 0, used, cb, res);
		return res;
	}

	//还可以在每层维护uset数组来在层内去重
	void Helper2(vector<int>& candidates, int target, int sum, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}

		unordered_set<int> uset;
		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			if (uset.find(candidates[i]) != uset.end()) continue;

			uset.insert(candidates[i]);  //只在层内去重，不用回溯
			cb.push_back(candidates[i]);
			Helper2(candidates, target, sum + candidates[i], i + 1, cb, res);
			cb.pop_back();
		}
	}

	//第二次做
	vector<int>path;
	vector<vector<int>> res;
	vector<vector<int>> combinationSum22(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, target, 0);
		return res;
	}

	void backtracking(vector<int>& candidates, int target, int startIndex) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
			//if(!path.empty() && candidates[i]==path.back()) continue;  //这个只能用在树枝去重，没法用在树层去重
			if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
			//这里应该是要在树层去重，树枝上不用去
			path.push_back(candidates[i]);
			backtracking(candidates, target - candidates[i], i + 1);
			path.pop_back();
		}
	}

	//还可以使用used数组来树层去重，used数组既可以用在树层去重，又可以用在树枝去重。used数组用在树层去重是used[i-1]==false,说明前一个节点已经回溯回来，已经使用过了。
	//used[i-1]==true，是树枝去重，表示在当前递归的路径上，前一个节点已经使用过了。
	//使用used数组在树层去重
	vector<vector<int>> combinationSum3(vector<int>& candidates, int target) {
		vector<bool> used(candidates.size(), false);

		sort(candidates.begin(), candidates.end());
		backtracking3(candidates, target, 0, used);
		return res;
	}

	void backtracking3(vector<int>& candidates, int target, int startIndex, vector<bool>& used) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
			//树层去重
			used[i] = true;
			path.push_back(candidates[i]);
			backtracking3(candidates, target - candidates[i], i + 1, used);
			path.pop_back();
			used[i] = false;
		}
	}

	// 第三次做
	// 这个题主要是树层去重
	// 其实既可以使用used数组去重，又可以使用i>startIndex && candidates[i] == candidates[i - 1]来去重
	vector<vector<int>> combinationSum4(vector<int>& candidates, int target) {
		path.clear();
		res.clear();
		vector<bool> used(candidates.size(), false);

		sort(candidates.begin(), candidates.end());
		backtracking4(candidates, target, 0, used);
		return res;
	}

	void backtracking4(vector<int>& candidates, int target, int startIndex,
		vector<bool>& used) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex;
			i < candidates.size() && target - candidates[i] >= 0; i++) {
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)  // 开始的时候我在想为什么这里要写used[i-1]==false呢，好像不用这个条件也可以。
				//后来试了一下发现，如果没有used[i-1]==false这个条件，如果两个相邻数相同，会树枝去重。
				continue;
			used[i] = true;
			path.push_back(candidates[i]);
			backtracking4(candidates, target - candidates[i], i + 1, used);
			path.pop_back();
			used[i] = false;
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
	cout << "------------" << endl;
	vector<vector<int>> res1 = st.combinationSum21(candidates, target);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[i].size(); j++)
			cout << res1[i][j] << " ";
		cout << endl;
	}
	cout << "------------" << endl;

	vector<vector<int>> res4 = st.combinationSum4(candidates, target);
	for (int i = 0; i < res4.size(); i++) {
		for (int j = 0; j < res4[i].size(); j++)
			cout << res4[i][j] << " ";
		cout << endl;
	}
}