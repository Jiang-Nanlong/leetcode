#include <iostream>
#include <vector>
using namespace std;

//�����е�ÿ��������һ��������nums[i]��-10��10֮�䣬�����Ҫ������������ȫ���У�
//��ô��ÿ����֦��ÿһ�㶼�ð����е��������Ǳ飬����forѭ����0��ʼ��
//������ص�ȥ�ز����������ϣ���������֦��ȥ���Ѿ�ʹ�ù���Ԫ�أ�����ʹ��used������Ϊ����������֦��ÿһ��ʹ��

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

	//�ڶ�������ֻ�Ǹо�Ӧ����һ��used��������ʶÿһ��Ԫ���ǲ��Ǳ�ʹ�ù���
	vector<int> path;
	vector<vector<int>> res;
	vector<vector<int>> permute1(vector<int>& nums) {
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
			if (used[i])
				continue;
			used[i] = true;
			path.push_back(nums[i]);
			backtracking(nums, used);
			path.pop_back();
			used[i] = false;
		}
	}

	// ��������
	vector<vector<int>> permute2(vector<int>& nums) {
		path.clear();
		res.clear();
		vector<bool> used(nums.size(), false);
		backtracking2(nums, used);
		return res;
	}

	void backtracking2(vector<int>& nums, vector<bool>& used) {
		if (path.size() == nums.size()) {
			res.push_back(path);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[i] == false) {
				path.push_back(nums[i]);
				used[i] = true;
				backtracking2(nums, used);
				used[i] = false;
				path.pop_back();
			}
		}
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> res = st.permute(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	cout << "------------" << endl;
	vector<vector<int>> res2 = st.permute2(nums);
	for (int i = 0; i < res2.size(); i++) {
		for (int j = 0; j < res2[i].size(); j++)
			cout << res2[i][j] << " ";
		cout << endl;
	}
	return 0;
}