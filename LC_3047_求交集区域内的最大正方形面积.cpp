#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
		int n = bottomLeft.size();
		long long res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int left = max(bottomLeft[i][0], bottomLeft[j][0]);
				int right = min(topRight[i][0], topRight[j][0]);
				int top = min(topRight[i][1], topRight[j][1]);
				int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
				long long weight = min(top - bottom, right - left);
				if (weight >= 0)
					res = max(res, weight * weight);
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<vector<int>> bottomLeft{ {1, 1}, {2, 2}, {3, 1} }, topRight{ {3, 3}, {4, 4}, {6, 6} };
	cout << st.largestSquareArea(bottomLeft, topRight) << endl;
	return 0;
}