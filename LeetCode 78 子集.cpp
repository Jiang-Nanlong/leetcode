#include <iostream>
#include <vector>
using namespace std;

//给定一个整数数组nums，数组中的元素互不相同，返回该数组的所有子集。
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
	//上边是我自己写的代码，在每层每次进入树枝之前，都保存一下结果，但是这样没法保存空集。

	//下边这是代码随想录的代码，他这个虽说只是换了res.push_back(cb);的位置，但是看起来更合理，也可以自己把空集加进去
	void Helper1(vector<int>& nums, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		res.push_back(cb);
		if (startindex == nums.size()) return;   //终止语句有没有都可以

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