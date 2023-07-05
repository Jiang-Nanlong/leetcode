/*
跳跃游戏和上一次差不多，但是这次要返回到达终点需要的最小步数
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int curdistance = 0, nextdistance = 0, count = 0;
		int m = nums.size();
		for (int i = 0; i < m - 1; i++) {   //这里不需要遍历到最后一个点，只需要遍历到倒数第二个节点就行
			nextdistance = max(nums[i] + i, nextdistance);
			if (i == curdistance) {  //如果当前已经到达当前这一步可以走到的最远的范围，感觉这里有点二叉树的层序遍历的意思了
				curdistance = nextdistance;
				count++;
			}
		}
		return count;
	}
};
//感觉几天不看，现在重新回来看这个题，好像有点理解其中的意思了
int main() {
	vector<int> nums1 = { 2,3,1,1,4 };
	vector<int> nums2 = { 2,3,0,1,4 };
	Solution s;
	cout << s.jump(nums1) << endl;
	cout << s.jump(nums2) << endl;
	return 0;
}