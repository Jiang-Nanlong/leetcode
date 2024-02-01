#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//判断两个气球是否重叠很好想，但是三个气球是否重叠，我一直想不明白怎么弄。这里要先按左边界排序，如果不排序的话就得考虑第二个气球的左边界是否位于
// 第一个气球的界限中间，如果按左边界排好序以后，我们从左到右捋过去就不用考虑第二个球的左边界和上一个的左边界之间的大小问题了。
//看了代码随想录的视频才明白，要更新右边界的最小值，如果下一个气球的最小值小于右边界，就不需要新添加箭。
//另外有一个地方需要注意，xstart ≤ x ≤ xend，表示如果两个球挨着也可以用一根箭射爆

class Solution {
public:
	static bool cmp(vector<int>& a, vector<int>& b) {
		return a[0] < b[0];  //按左边界从小到大排序
	}
	int findMinArrowShots(vector<vector<int>>& points) {
		int count = 1;
		sort(points.begin(), points.end(), cmp);
		int minrightmrigin = points[0][1];
		for (int i = 1; i < points.size(); i++) {
			if (points[i][0] > minrightmrigin) {  //如果第二个气球的左边界大于最小右边界
				count++;							//箭加1，更新右边界
				minrightmrigin = points[i][1];
			}
			else {
				minrightmrigin = min(minrightmrigin, points[i][1]);
			}
		}
		return count;
	}
};

int main() {
	Solution st;
	vector<vector<int>> points{ {7,15} ,{6,14},{8,12},{3,4},{4,13},{6,14},{9,11},{6,12},{4,13} };
	int count = st.findMinArrowShots(points);
	cout << count << endl;
	return 0;
}


//以下是之前写的代码
/*
有一些气球在XY平面上，points数组中记录球的信息，points[i]=[Xstart,Xend]，记录着气球的直径，但并未给出具体的y值，有一只箭从x轴的某处垂直于x轴射出，如果箭射出的位置在
气球的直径内就可以将球射爆，箭射出以后可以无限前进，返回射爆所有气球所需要的最少的箭数
*/
//这个题和之前435移除最小的区间数的题有点像，都是区间问题的，这个应该是统计有多少组气球是重叠的，但是又不能只统计重叠，还得考虑重叠的气球有一个最小的交集
//后来发现只需要按右边界排序，然后从左只有遍历区间即可，因为此时最开始的区间就是最小的，如果当前区间不满足了，在往后又是一个相对最小的区间
/*
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
*/