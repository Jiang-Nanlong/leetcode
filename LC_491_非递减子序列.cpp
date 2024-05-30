#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//����һ���������飬�ҳ��������в�ͬ�ĵ��������У�������������������Ԫ�أ��⼯�в������ظ���
//�����ֻ����������ȥ�ؾ���

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

		int used[201] = { 0 };  //����Ҳ������set��������Ŀ˵nums[i]��-100��100֮�䣬���Կ�����������졣
		for (int i = startindex; i < nums.size(); i++) {
			if ((!cb.empty() && nums[i] < cb.back()) || (used[100 + nums[i]] == 1))
				continue;
			used[nums[i] + 100] = 1;  //�����used���鲻�û��ݣ���Ϊ����ÿһ����֦�϶����´�����ֻ���������ϲŻᱣ�֣����Կ���ֻ������ȥ��
			cb.push_back(nums[i]);
			Helper(nums, i + 1, cb, res);
			cb.pop_back();
		}
	}

	//�ڶ�������û����������������ֻ��ʹ��uset����ȥ�أ�����ԭ���鲻����������
	vector<vector<int>> res;
	vector<int> path;
	vector<vector<int>> findSubsequences1(vector<int>& nums) {
		backtracking(nums, 0);
		return res;
	}

	void backtracking(vector<int>& nums, int startIndex) {
		if (path.size() >= 2)
			res.push_back(path);
		if (startIndex == nums.size()) {
			return;
		}
		unordered_set<int> uset;
		for (int i = startIndex; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end()) continue;

			if (path.empty() || path.back() <= nums[i]) {
				uset.insert(nums[i]);
				path.push_back(nums[i]);
				backtracking(nums, i + 1);
				path.pop_back();
			}
		}
	}

	//��Ϊ����֪����nums[i]�ķ�Χ�����Կ���ֱ��ʹ������������uset
	vector<vector<int>> findSubsequences2(vector<int>& nums) {
		backtracking1(nums, 0);
		return res;
	}

	void backtracking1(vector<int>& nums, int startIndex) {
		if (path.size() >= 2)
			res.push_back(path);
		if (startIndex == nums.size()) {
			return;
		}
		int used[201] = { 0 };  //���߿��԰�int��Ϊbool
		for (int i = startIndex; i < nums.size(); i++) {
			if (used[nums[i] + 100]) continue;

			if (path.empty() || path.back() <= nums[i]) {
				used[nums[i] + 100]++;
				path.push_back(nums[i]);
				backtracking1(nums, i + 1);
				path.pop_back();
			}
		}
	}

	//��������
	vector<vector<int>> findSubsequences3(vector<int>& nums) {
		path.clear();
		res.clear();
		backtracking3(nums, 0);
		return res;
	}

	void backtracking3(vector<int>& nums, int start) {
		if (path.size() >= 2)
			res.push_back(path);

		if (start == nums.size())
			return;

		unordered_set<int> uset;
		for (int i = start; i < nums.size(); i++) {
			if (uset.find(nums[i]) != uset.end())
				continue;
			if (path.empty() || nums[i] >= path.back()) {
				path.push_back(nums[i]);
				uset.insert(nums[i]);
				backtracking3(nums, i + 1);
				path.pop_back();
			}
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

	cout << "---------------------" << endl;

	vector<vector<int>> res3 = st.findSubsequences3(nums);
	for (int i = 0; i < res3.size(); i++) {
		for (int j = 0; j < res3[i].size(); j++)
			cout << res3[i][j] << " ";
		cout << endl;
	}
}