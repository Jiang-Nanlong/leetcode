#include <iostream>
#include <vector>
using namespace std;

//给定一个升序数组和一个目标值，在数组中找到目标值并返回其索引，否则返回其应该插入的位置

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				return mid;
		}
		return left;
	}
};

int main() {
	Solution st;
	vector<int> nums = { 1, 3, 5, 6 };
	int target = 2;
	cout << st.searchInsert(nums, target) << endl;
	return 0;
}