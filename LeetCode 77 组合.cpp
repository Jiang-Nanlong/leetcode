#include <iostream>
#include <vector>
using namespace std;

//������������n��k������[1,n]�����п��ܵ�k���������

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> cb;
		vector<vector<int>> res;
		Helper(n, k, 1, cb, res);
		return res;
	}
	void Helper(int n, int k, int startindex, vector<int>& cb, vector<vector<int>>& res) {
		if (cb.size() == k) {
			res.push_back(cb);
			return;
		}

		for (int i = startindex; i <= n; i++) {  //����ط��������Ż�һ�£�
			//����˵Ҫ�ҵ�5��������ϣ����Ǵ�startindex����������Ѿ�����������ˣ���ô��һ�ξͿ��Լ�֦��
			//���԰�i <= n������i<=n-(k-cb.size())+1
			cb.push_back(i);
			Helper(n, k, i + 1, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<vector<int>> res = st.combine(4, 2);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << "  ";
		cout << endl;
	}
}