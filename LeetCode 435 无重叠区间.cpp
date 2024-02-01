#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这个题要计算至少移除多少个区间，可以使得剩余的区间不重叠。其实就是要统计有多少重叠的区间。
//这个题可以模仿LeetCode 452 最少箭来射爆气球的题来写。那个题是遇到重叠区间 箭数不用加1，这个题正好相反，遇到重叠区间，count就++
//其实还可以把射箭的程序照搬过来，只需要把最后的return语句改为return intervals.size()-count就行，这里的count是箭的数量。

class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int count = 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int minrightmrigin = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] >= minrightmrigin)
				minrightmrigin = intervals[i][1];
			else {
				minrightmrigin = min(minrightmrigin, intervals[i][1]);
				count++;
			}
		}
		return count;
	}
};

int main() {
	Solution st;
	vector<vector<int>> intervals{ {1,2} ,{2,3},{3,4},{1,3} };
	int count = st.eraseOverlapIntervals(intervals);
	cout << count << endl;
	return 0;
}

//以下是之前写的代码

/*
给定一个区间的集合，返回需要移除区间的最小数量，是剩余的区间互不重叠
*/
//看到这种区间问题我真是一点思路都没有，嚓
//今天懒得做了，嚓，明天来了再说吧
//昨天看了题解，大致意思就是说按区间的右边界或者左边界排序，以按右边界排序为例，右边界从小到大排序，然后在从左向右依次遍历，
//从最小的右边界的区间开始，每次记录当前区间的右边界，然后以这个数为标准，继续往右找与它不重叠的区间的左边界，依次进行，最后记录一共多少个重叠的区间
/*
class Solution {
public:
	static int cmp(vector<int>& x, vector<int>& y) {   //按右边界进行排序
		return x[1] < y[1];
	}

	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty())return 0;
		int m = intervals.size();
		sort(intervals.begin(), intervals.end(), cmp);
		//记录要移除的区间数》》
		int temp = intervals[0][1], removed = 0;
		for (int i = 1; i < m; i++) {
			if (intervals[i][0] < temp) {
				removed++;
			}
			else {
				temp = intervals[i][1];
			}
		}
		//记录要移除的区间数《《

		//记录没有相交的区间数》》
		temp = intervals[0][1];
		int count = 1;
		for (int i = 1; i < m; i++) {
			if (intervals[i][0] >= temp) {
				count++;
				temp = intervals[i][1];
			}
		}
		//记录没有相交的区间数《《
		//这两种方法都可以，如果记录的是要移除的区间数，直接返回即可，如果记录的是不相交的区间数，最后返回差值。
		// 不过我对于区间从左向右遍历还是从右向左遍历有点弄不清
		//return removed;
		return m - count;
	}
};

//按照右边界排序，就要从左向右遍历，因为右边界越小越好，只要右边界越小，留给下一个区间的空间就越大，所以从左向右遍历，优先选右边界小的。
//按照左边界排序，就要从右向左遍历，因为左边界数值越大越好（越靠右），这样就给前一个区间的空间就越大，所以可以从右向左遍历。
//右边界排序之后，局部最优：优先选右边界小的区间，所以从左向右遍历，留给下一个区间的空间大一些，从而尽量避免交叉。全局最优：选取最多的非交叉区间。

int main() {
	vector<vector<int>> intervals1 = { {1,2},{2,3},{3,4} ,{1,3} };
	vector<vector<int>> intervals2 = { {1,2},{1,2},{1,2} };
	vector<vector<int>> intervals3 = { {1,2},{2,3} };
	Solution s;
	cout << s.eraseOverlapIntervals(intervals1) << endl;
	cout << s.eraseOverlapIntervals(intervals2) << endl;
	cout << s.eraseOverlapIntervals(intervals3) << endl;

	return 0;
}
*/