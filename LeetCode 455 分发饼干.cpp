/*
这是一道关于贪心算法的简单题
题目要求每个孩子都有一个胃口值，饼干有大小，如果饼干的大小大于等于孩子的胃口值，说明饼干可以让孩子吃饱，问最多能让多少个孩子吃饱
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
看到这道题后第一反应是先把孩子数组和饼干数组都进行从小到大的排序，然后循环孩子数组，相对应的饼干数组每次都从上一次的结果继续向下
*/
class Solution {
public:
	int findContentChildren(vector<int>& child, vector<int>& cookie) {
		sort(child.begin(), child.end());
		sort(cookie.begin(), cookie.end());
		int children = 0, cookies = 0;
		while (children < child.size() && cookies < cookie.size()) {
			if (child[children] <= cookie[cookies])   //可以吃饱
				children++;
			cookies++;
		}
		return children;
	}
};
//这道题的思路比较简单，可以说是不需要任何的算法思路都可以做出来。

int main() {
	vector<int> child1 = { 1,2,3 }, cookie1 = { 1,1 };
	vector<int> child2 = { 1,2 }, cookie2 = { 1,2,3 };
	Solution s;
	cout << s.findContentChildren(child1, cookie1) << endl;
	cout << s.findContentChildren(child2, cookie2) << endl;

	return 0;
}