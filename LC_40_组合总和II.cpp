#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//����һ��candidates���飬�ҳ������к�Ϊtarget����ϡ�������LeetCode 39��һ���ĵط����������п������ظ����������ǽ⼯�в��ܰ����ظ����
//���ݽ�������ⶼ���Գ�������νṹ��
//������������ȥ�ص����⣬һ�����п��԰����ظ�Ԫ�أ����ǽ⼯�в��ܰ����ظ��⣬���������ȥ����������ȥ�أ�����������֦ȥ�ء�


class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> cb;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		Helper(candidates, target, 0, 0, cb, res);
		return res;
	}

	void Helper(vector<int>& candidates, int target, int sum, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}

		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			if (i > startindex && candidates[i] == candidates[i - 1]) continue;   //��һ���ҿ�ʼ��i>startindexд��i>0�ˣ����д��i>0�Ļ����ͻ���������һ�����������������֦֮�䶼ȥ���ˡ�
			//�������ȥ���������Ĺؼ���
			cb.push_back(candidates[i]);
			Helper(candidates, target, sum + candidates[i], i + 1, cb, res);
			cb.pop_back();
		}
	}

	//ʹ��used������ȥ��
	void Helper1(vector<int>& candidates, int target, int sum, int startindex, vector<bool>& used, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}

		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
				//used����������ȥ�أ�����������У���ǰ�ڵ��ֵ����һ��ֵһ������ôused[i-1]==false����Ϊ��һ���ڵ��Ѿ����ݻ����ˣ�
				//ֻ�е�����֦��ʱ��used[i-1]�Ż���true
				//used[i-1]==false��������ȥ�أ�used[i-1]==true������֦ȥ�أ���Щ����ʹ������ȥ�غ���֦ȥ�ض���������������ȥ�ص�Ч�ʻ����һЩ��
				continue;
			cb.push_back(candidates[i]);
			used[i] = true;
			Helper1(candidates, target, sum + candidates[i], i + 1, used, cb, res);
			used[i] = false;
			cb.pop_back();
		}
	}
	vector<vector<int>> combinationSum21(vector<int>& candidates, int target) {
		vector<int> cb;
		vector<vector<int>> res;
		vector<bool> used(candidates.size(), false);
		sort(candidates.begin(), candidates.end());
		Helper1(candidates, target, 0, 0, used, cb, res);
		return res;
	}

	//��������ÿ��ά��uset�������ڲ���ȥ��
	void Helper2(vector<int>& candidates, int target, int sum, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (sum == target) {
			res.push_back(cb);
			return;
		}

		unordered_set<int> uset;
		for (int i = startindex; i < candidates.size() && sum + candidates[i] <= target; i++) {
			if (uset.find(candidates[i]) != uset.end()) continue;

			uset.insert(candidates[i]);  //ֻ�ڲ���ȥ�أ����û���
			cb.push_back(candidates[i]);
			Helper2(candidates, target, sum + candidates[i], i + 1, cb, res);
			cb.pop_back();
		}
	}

	//�ڶ�����
	vector<int>path;
	vector<vector<int>> res;
	vector<vector<int>> combinationSum22(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, target, 0);
		return res;
	}

	void backtracking(vector<int>& candidates, int target, int startIndex) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
			//if(!path.empty() && candidates[i]==path.back()) continue;  //���ֻ��������֦ȥ�أ�û����������ȥ��
			if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
			//����Ӧ����Ҫ������ȥ�أ���֦�ϲ���ȥ
			path.push_back(candidates[i]);
			backtracking(candidates, target - candidates[i], i + 1);
			path.pop_back();
		}
	}

	//������ʹ��used����������ȥ�أ�used����ȿ�����������ȥ�أ��ֿ���������֦ȥ�ء�used������������ȥ����used[i-1]==false,˵��ǰһ���ڵ��Ѿ����ݻ������Ѿ�ʹ�ù��ˡ�
	//used[i-1]==true������֦ȥ�أ���ʾ�ڵ�ǰ�ݹ��·���ϣ�ǰһ���ڵ��Ѿ�ʹ�ù��ˡ�
	//ʹ��used����������ȥ��
	vector<vector<int>> combinationSum3(vector<int>& candidates, int target) {
		vector<bool> used(candidates.size(), false);

		sort(candidates.begin(), candidates.end());
		backtracking3(candidates, target, 0, used);
		return res;
	}

	void backtracking3(vector<int>& candidates, int target, int startIndex, vector<bool>& used) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
			//����ȥ��
			used[i] = true;
			path.push_back(candidates[i]);
			backtracking3(candidates, target - candidates[i], i + 1, used);
			path.pop_back();
			used[i] = false;
		}
	}

	// ��������
	// �������Ҫ������ȥ��
	// ��ʵ�ȿ���ʹ��used����ȥ�أ��ֿ���ʹ��i>startIndex && candidates[i] == candidates[i - 1]��ȥ��
	vector<vector<int>> combinationSum4(vector<int>& candidates, int target) {
		path.clear();
		res.clear();
		vector<bool> used(candidates.size(), false);

		sort(candidates.begin(), candidates.end());
		backtracking4(candidates, target, 0, used);
		return res;
	}

	void backtracking4(vector<int>& candidates, int target, int startIndex,
		vector<bool>& used) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex;
			i < candidates.size() && target - candidates[i] >= 0; i++) {
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)  // ��ʼ��ʱ��������Ϊʲô����Ҫдused[i-1]==false�أ��������������Ҳ���ԡ�
				//��������һ�·��֣����û��used[i-1]==false������������������������ͬ������֦ȥ�ء�
				continue;
			used[i] = true;
			path.push_back(candidates[i]);
			backtracking4(candidates, target - candidates[i], i + 1, used);
			path.pop_back();
			used[i] = false;
		}
	}
};

void main() {
	Solution st;
	vector<int> candidates{ 10,1,2,7,6,1,5 };
	int target = 8;
	vector<vector<int>> res = st.combinationSum2(candidates, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << "------------" << endl;
	vector<vector<int>> res1 = st.combinationSum21(candidates, target);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[i].size(); j++)
			cout << res1[i][j] << " ";
		cout << endl;
	}
	cout << "------------" << endl;

	vector<vector<int>> res4 = st.combinationSum4(candidates, target);
	for (int i = 0; i < res4.size(); i++) {
		for (int j = 0; j < res4[i].size(); j++)
			cout << res4[i][j] << " ";
		cout << endl;
	}
}