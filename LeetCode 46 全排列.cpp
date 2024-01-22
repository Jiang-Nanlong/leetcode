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
};

void main() {
	Solution st;
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> res = st.permute(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}