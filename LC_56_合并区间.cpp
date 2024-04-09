#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//合并重叠的区间，这个还是区间问题，跟射箭，无重叠区间，划分字母一样

class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end(), cmp);
		int left = intervals[0][0], right = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] > right) {
				res.push_back({ left,right });
				left = intervals[i][0];
				right = intervals[i][1];
			}
			else {
				right = max(right, intervals[i][1]);
			}
		}
		res.push_back({ left,right });
		return res;
	}

	//第二次做
	static bool cmp1(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
	vector<vector<int>> merge1(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp1);
		vector<vector<int>> res;
		int leftboard = intervals[0][0], rightboard = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] <= rightboard)
				rightboard = max(rightboard, intervals[i][1]);
			else {
				res.push_back({ leftboard, rightboard });
				leftboard = intervals[i][0];
				rightboard = intervals[i][1];
			}
		}
		res.push_back({ leftboard, rightboard });
		return res;
	}
};

int main() {
	Solution st;
	vector<vector<int>> intervals{ {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>> res = st.merge(intervals);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ",";
		}
		cout << "  ";
	}
	return 0;
}

//以下是我之前写的代码
/*
* 给定一个区间的集合，合并所有重叠的区间。
*/
/*
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		if (intervals.size() == 0) return res;
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[1] > b[1]; });  //我今天才知道，这种写法会更快
		int left = intervals[0][0], right = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			if (left <= intervals[i][1] && right >= intervals[i][0]) {
				left = min(left, intervals[i][0]);
			}
			else {
				res.push_back({ left,right });
				left = intervals[i][0], right = intervals[i][1];
			}
		}
		res.push_back({ left,right });
		return res;
	}
};

int main() {
	vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} }, res;
	vector<vector<int>> intervals1 = { {2,3},{4,5},{6,7},{8,9},{1,10} };
	vector<vector<int>> intervals2 = { {1,4},{5,6} };
	Solution s;
	res = s.merge(intervals);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << "," << res[i][1] << endl;
	}
	res = s.merge(intervals1);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << "," << res[i][1] << endl;
	}
	res = s.merge(intervals2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << "," << res[i][1] << endl;
	}
	return 0;
}
*/