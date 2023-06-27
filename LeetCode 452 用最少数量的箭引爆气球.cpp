/*
有一些气球在XY平面上，points数组中记录球的信息，points[i]=[Xstart,Xend]，记录着气球的直径，但并未给出具体的y值，有一只箭从x轴的某处垂直于x轴射出，如果箭射出的位置在
气球的直径内就可以将球射爆，箭射出以后可以无限前进，返回射爆所有气球所需要的最少的箭数
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这个题和之前435移除最小的区间数的题有点像，都是区间问题的，这个应该是统计有多少组气球是重叠的，但是又不能只统计重叠，还得考虑重叠的气球有一个最小的交集
//后来发现只需要按右边界排序，然后从左只有遍历区间即可，因为此时最开始的区间就是最小的，如果当前区间不满足了，在往后又是一个相对最小的区间
class Solution {
public:
	static int cmp(vector<int>& x, vector<int>& y) {   //按右边界进行排序
		return x[1] < y[1];
	}
	
	//int finMinArrowShots(vector<vector<int>>& points) {
	//	int m = points.size();
	//	if (m == 0) return 0;
	//	sort(points.begin(), points.end(), cmp);
	//	int count = 1, i = 0, temp = points[0][1];
	//	while (i < m) {
	//		if (points[i][0] <= temp && points[i][1] >= temp) {
	//			i++;
	//		}
	//		else {
	//			temp = points[i][1];
	//			count++;
	//			//i++;  下午回来优化一下这里
	//		}
	//	}
	//	return count;
	//}

	int finMinArrowShots(vector<vector<int>>& points) {
		int m = points.size();
		if (m == 0) return 0;
		sort(points.begin(), points.end(), cmp);
		int count = 1, i = 0, temp = points[0][1];
		for (int i = 0; i < m; i++) {
			if (temp < points[i][0]) {
				temp = points[i][1];
				count++;
			}
		}
		return count;
	}
};

int main() {
	vector<vector<int>> points1 = { {1,2},{3,4},{5,6},{7,8} };
	vector<vector<int>> points2 = { {1,2},{2,3},{3,4},{4,5} };
	Solution s;
	cout << s.finMinArrowShots(points1) << endl;
	cout << s.finMinArrowShots(points2) << endl;
	return 0;
}