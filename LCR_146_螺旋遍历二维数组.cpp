#include <iostream>
#include <vector>
using namespace std;
/*
* Õâ¸ö¸úLeetCode 54ÌâÒ»Ñù
*/

class Solution {
public:
	vector<int> spiralArray(vector<vector<int>>& array) {

		if (array.empty())return {};
		int m = array.size(), n = array[0].size();
		vector<int> res;
		int loop = min(m, n) / 2, i = 0, j = 0, count = 0;
		for (int k = 0; k <= loop; k++) {
			i = k;
			j = k;
			for (; j < n - k && count < m * n; j++) {
				res.push_back(array[i][j]);
				++count;
			}
			for (--j, ++i; i < m - k && count < m * n; i++) {
				res.push_back(array[i][j]);
				++count;
			}
			for (--i, --j; j >= k && count < m * n; j--) {
				res.push_back(array[i][j]);
				++count;
			}
			for (--i, ++j; i > k && count < m * n; i--) {
				res.push_back(array[i][j]);
				++count;
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<vector<int>> array{ {1,2,3},{4,5,6},{7,8,9} };
	vector<int> res = st.spiralArray(array);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "  ";
	cout << endl;
	return 0;
}
