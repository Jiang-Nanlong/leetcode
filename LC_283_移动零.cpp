#include <iostream>
#include <vector>
using namespace std;

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//用双指针

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int slow = 0, fast = 0;
		for (; fast < nums.size(); fast++) {
			if (nums[fast] != 0)
				nums[slow++] = nums[fast];
		}
		while (slow < nums.size())
			nums[slow++] = 0;
	}

	//下边是第二次做的代码
	void moveZeroes1(vector<int>& nums) {
		int i = 0, j = 0;
		for (; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[j] = nums[i];
				j++;
			}
		}
		while (j < nums.size()) {
			nums[j++] = 0;
		}
	}
};

void main() {
	Solution st;
	vector<int> nums{ 0,1,0,3,12 };
	st.moveZeroes(nums);
	for (auto c : nums)
		cout << c << " ";
	cout << endl;
	vector<int> nums1{ 0,1,0,3,12 };
	st.moveZeroes1(nums1);
	for (auto c : nums1)
		cout << c << " ";
	cout << endl;
	cout << __cplusplus << endl;
	cout << _MSVC_LANG << endl;
}
