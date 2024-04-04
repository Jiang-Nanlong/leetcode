#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//������LeetCode 78 �Ӽ���һ�㲻һ����������nums�����п������ظ�Ԫ�أ����ǽ⼯�в��ܰ����ظ���

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
			if (i > startindex && nums[i] == nums[i - 1]) continue;   //���������ظ���
			//����ط���LeetCode 40 ����ܺ�II���һ��
			cb.push_back(nums[i]);
			Helper(nums, i + 1, cb, res);
			cb.pop_back();
		}
	}

	//������ʹ��used����ȥ��
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

	//������ģ��LeetCode 491 �ǵݼ������У���ÿһ�㴴��һ��unordered_set���ڲ���ȥ��
	void Helper2(vector<int>& nums, int startIndex, vector<int>& cb, vector<vector<int>>& res) {
		res.push_back(cb);
		unordered_set<int> uset;
		for (int i = startIndex; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end()) {
				continue;
			}
			uset.insert(nums[i]);  //��Ϊֻ��ÿһ��ά�����uset���飬���Բ��ø������ݾ���
			cb.push_back(nums[i]);
			Helper2(nums, i + 1, cb, res);
			cb.pop_back();
		}
	}

	//�ڶ�����
	vector<int> path;
	vector<vector<int>> res;

	vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		backtracking(nums, 0);
		return res;
	}

	void backtracking(vector<int>& nums, int startIndex) {
		res.push_back(path);
		if (startIndex == nums.size())
			return;

		for (int i = startIndex; i < nums.size(); i++) {
			if (i > startIndex && nums[i] == nums[i - 1])  //����ȥ��
				continue;
			path.push_back(nums[i]);
			backtracking(nums, i + 1);
			path.pop_back();
		}
	}

	//ʹ��used��������ȥ��
	vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
		vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end());
		backtracking1(nums, 0, used);
		return res;
	}

	void backtracking1(vector<int>& nums, int startIndex, vector<bool>& used) {
		res.push_back(path);
		if (startIndex == nums.size())
			return;

		for (int i = startIndex; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
				continue;
			path.push_back(nums[i]);
			used[i] = true;
			backtracking1(nums, i + 1, used);
			used[i] = false;
			path.pop_back();
		}
	}

	//ʹ��uset����ȥ��
	vector<vector<int>> subsetsWithDup3(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		backtracking2(nums, 0);
		return res;
	}

	void backtracking2(vector<int>& nums, int startIndex) {
		res.push_back(path);
		if (startIndex == nums.size())
			return;

		unordered_set<int> uset;
		for (int i = startIndex; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end()) continue;

			uset.insert(nums[i]);
			path.push_back(nums[i]);
			backtracking2(nums, i + 1);
			path.pop_back();
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