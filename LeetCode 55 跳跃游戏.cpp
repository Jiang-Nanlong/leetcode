/*
给定一个非负数组，最开始从数组的第一个位置，数中的每个元素代表着从当前位置可以跳出的最大距离，判断能否跳到最后一个
*/
#include <iostream>
#include <vector>
using namespace std;

//题目的重点应该放在每次移动可以跳出的范围，不必纠结每一次从哪个位置开始跳
//嚓，贪心算法怎么这么难想，更像常识，理解的很好理解，不好理解的太难想了，嚓，每次要看解答才能看懂，本以为很复杂的代码，最后程序却很简单
//嚓
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int count = 0;
		if (nums.size() == 1) return true;
		for (int i = 0; i <= count; i++) {
			count = max(i + nums[i], count);
			if (count >= nums.size() - 1)return true;
		}
		return false;
	}
};

int main() {
	vector<int> nums1 = { 2,3,1,1,4 };
	vector<int> nums2 = { 3,2,1,0,4 };
	Solution s;
	cout << s.canJump(nums1) << endl;
	cout << s.canJump(nums2) << endl;
	return 0;
}