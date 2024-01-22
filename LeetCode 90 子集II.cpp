#include <iostream>
#include <vector>
#include <algorithm>
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