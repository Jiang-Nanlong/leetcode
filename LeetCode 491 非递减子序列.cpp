#include <iostream>
#include <vector>
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