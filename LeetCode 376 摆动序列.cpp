/*
如果连续的数字之间的差严格的在正数和负数之间交替，则数字序列为摆动序列。第一个差(如果存在的话)可以是正数或者负数，
仅含有一个元素或者两个不等元素的序列也视为摆动序列。子序列可通过从原始序列中删除一些（也可不删除）元素来获得，剩下的元素保持原始顺序。
返回原始数组中摆动序列的最长子序列的长度，注：摆动序列在原始序列中可以不连续。
*/
#include <iostream>
#include <vector>
using namespace std;

//题目中“如果连续的数字之间的差严格在正数和负数之间交替，则数字序列为摆动序列”，可以作为判断条件，如果前一个差和后一个差异号就行
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int m = nums.size();
		if (m < 2) return m;  //m=0或1
		int preDiff = 0, curDiff = 0, result = 1;  //拿数组只有两个数字举例子，最左边的第一个数字自动考虑在内，所以起始result=1，最后循环到达右边界的前一个
		for (int i = 0; i < m - 1; i++) {
			curDiff = nums[i + 1] - nums[i];
			if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
				preDiff = curDiff;
				result++;
			}
		}
		return result;
	}
};

int main() {
	vector<int> nums1 = { 1,7,4,9,2,5 };
	vector<int> nums2 = { 1,17,5,10,13,15,10,5,16,8 };
	vector<int> nums3 = { 1,2,3,4,5,6,7,8,9 };
	Solution s;
	cout << s.wiggleMaxLength(nums1) << endl;
	cout << s.wiggleMaxLength(nums2) << endl;
	cout << s.wiggleMaxLength(nums3) << endl;

	return 0;
}