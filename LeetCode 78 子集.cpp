#include <iostream>
#include <vector>
using namespace std;

//����һ����������nums�������е�Ԫ�ػ�����ͬ�����ظ�����������Ӽ���
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> cb;
		vector<vector<int>> res;
		res.push_back(cb);
		Helper(nums, 0, cb, res);
		return res;
	}
	void Helper(vector<int>& nums, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		for (int i = startindex; i < nums.size(); i++) {
			cb.push_back(nums[i]);
			res.push_back(cb);
			Helper(nums, i + 1, cb, res);
			cb.pop_back();
		}
	}
	//�ϱ������Լ�д�Ĵ��룬��ÿ��ÿ�ν�����֦֮ǰ��������һ�½������������û������ռ���

	//�±����Ǵ�������¼�Ĵ��룬�������˵ֻ�ǻ���res.push_back(cb);��λ�ã����ǿ�����������Ҳ�����Լ��ѿռ��ӽ�ȥ
	void Helper1(vector<int>& nums, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		res.push_back(cb);
		if (startindex == nums.size()) return;   //��ֹ�����û�ж�����

		for (int i = startindex; i < nums.size(); i++) {
			cb.push_back(nums[i]);
			Helper1(nums, i + 1, cb, res);
			cb.pop_back();
		}
	}
	vector<vector<int>> subsets1(vector<int>& nums) {
		vector<int> cb;
		vector<vector<int>> res;
		Helper1(nums, 0, cb, res);
		return res;
	}
};

void main() {
	Solution st;
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> res = st.subsets(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	vector<vector<int>>res1 = st.subsets1(nums);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[i].size(); j++)
			cout << res1[i][j] << " ";
		cout << endl;
	}
}