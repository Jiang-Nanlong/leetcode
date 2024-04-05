#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//�����������ϸ��⣬��һ����ͬ�㣬����nums�����п������ظ����֣��⼯�в��ܰ����ظ���
//��ʵ��ô����������֦�ϵ��߼���46��һ����������������Ҫȥ�أ�һ��ʼû��������ôд
//�������˴����֪����ԭ�������ú�LeetCode 40 ����ܺ�II���߼�һ����������ȥ��
//��ô�룬used���黹ͦ�������ȿ�������֦�ϱ�ʾ�ĸ��Ѿ�ʹ�ã���������������ȥ�ء�

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> cb;
		vector<vector<int>> res;
		vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end());  //��Ҫ��������ͬ�����ֿ���һ��
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

	//Ҳ����ʹ��uset�����ڲ���ȥ��
	void Helper1(vector<int>& nums, vector<int>& cb, vector<vector<int>>& res, vector<bool>& used) {
		if (cb.size() == nums.size()) {
			res.push_back(cb);
			return;
		}

		unordered_set<int> uset;
		for (int i = 0; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end()) continue;//uset����������ȥ��
			if (used[i] == false) {			//used��������֦ȥ��
				uset.insert(nums[i]);
				used[i] == true;
				cb.push_back(nums[i]);
				Helper1(nums, cb, res, used);
				cb.pop_back();
				used[i] = false;
			}
		}
	}

	//�ڶ�������ʹ��used����������֦ȥ�� 
	vector<int> path;
	vector<vector<int>> res;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		backtracking(nums, used);
		return res;
	}

	void backtracking(vector<int>& nums, vector<bool>& used) {
		if (path.size() == nums.size()) {
			res.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
				continue;
			if (used[i])
				continue;
			used[i] = true;
			path.push_back(nums[i]);
			backtracking(nums, used);
			path.pop_back();
			used[i] = false;
		}
	}

	//����ʹ��uset����ȥ�أ�used��֦ȥ��
	void backtracking1(vector<int>& nums, vector<bool>& used) {
		if (path.size() == nums.size()) {
			res.push_back(path);
			return;
		}

		unordered_set<int> uset;
		for (int i = 0; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end())
				continue;
			if (used[i])
				continue;
			uset.insert(nums[i]);
			used[i] = true;
			path.push_back(nums[i]);
			backtracking1(nums, used);
			path.pop_back();
			used[i] = false;
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