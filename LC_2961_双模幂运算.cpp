#include <iostream>
#include <vector>
using namespace std;

// 快速幂第一题

class Solution {
public:
	vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
		vector<int> res;
		for (int i = 0; i < variables.size(); i++) {
			int a = variables[i][0], b = variables[i][1], c = variables[i][2],
				m = variables[i][3];
			if (fastPow(fastPow(a, b, 10), c, m) == target)
				res.push_back(i);
		}
		return res;
	}

	int fastPow(int a, int n, int mod) {
		int res = 1;
		while (n) {
			if (n & 1)
				res = res * a % mod;
			a = a * a % mod;
			n >>= 1;
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<vector<int>> variables{ {2,3,3,10}, { 3,3,3,1}, {6,1,1,4} };
	int target = 2;
	vector<int> res = st.getGoodIndices(variables, target);
	for (int i : res)
		cout << i << " ";
	cout << endl;

	return 0;
}
