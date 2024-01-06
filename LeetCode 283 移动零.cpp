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
};

void main() {
	Solution st;
	vector<int> nums{ 0,1,0,3,12 };
	st.moveZeroes(nums);
	for (auto c : nums)
		cout << c << " ";
	cout << endl;
	cout << __cplusplus << endl;
	cout << _MSVC_LANG << endl;
}