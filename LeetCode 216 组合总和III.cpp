#include <iostream>
#include <vector>
using namespace std;

//��1-9֮��ѡ��k����������ܺ�Ϊn

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> cb;
		vector<vector<int>> res;
		Helper(k, n, 1, 0, cb, res);
		return res;
	}
	void Helper(int k, int n, int startindex, long long sum, vector<int>& cb, vector<vector<int>>& res) {
		if (sum > n) return;  //��֦����

		if (cb.size() == k) {  //���ﲻ�ܰ���������д��һ�����д��һ�𣬼����ǵ�Ԫ����������kʱ������sum!=n����ô����Ҳ����return���ͻᳬʱ
			if (sum == n) res.push_back(cb);
			return;
		}

		for (int i = startindex; i <= 9 - (k - cb.size()) + 1; i++) {   //i<= 9 - (k - cb.size()) + 1 ��֦����
			cb.push_back(i);
			Helper(k, n, i + 1, sum + i, cb, res);  //֮�䴫��sum+i���Ӷ�����sum���ݣ�ֻ��cb���л���
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<vector<int>> res = st.combinationSum3(3, 7);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}