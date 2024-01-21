#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//������Ҫ�ڸ�����candidates�������ҳ������������Щ���ֵĺ͵���target��Ȼ��ÿ�����ֿ����ظ�ʹ�á�
//�ڼ�֦֮ǰ�������ǰֵ�Ѿ�����target�ˣ����������ȵ�ǰֵ�����������Ȼ�ʹ���target�ˣ��������ﻹ�ǻ���뵽��һ��ݹ飬����˷���ʱ�䡣
//���Կ����ȸ���������ֻ�е�sum���ϵ�ǰֵС�ڵ���target��ʱ�򣬲Ż����ݹ飬����Ѿ������ˣ��Ͳ�Ҫ������һ��ݹ��ˡ�
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> cb;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());  //�����֦����
		Helper(candidates, target, 0, 0, cb, res);
		return res;
	}

	void Helper(vector<int>& candidates, int target, int sum, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}
		//if (sum > target) return;  //��֦�Ժ�ȡ��

		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {  //sum + candidates[i] <= target��֦
			cb.push_back(candidates[i]);
			Helper(candidates, target, sum + candidates[i], i, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<int> candidates{ 2,3,5 };
	vector<vector<int>> res = st.combinationSum(candidates, 8);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}