#include<iostream>
#include<vector>
using namespace std;

class Solution {
	//[1,3]  3
public:
	int FindNumber(vector<int> nums, int target) 
	{
		int length = nums.size();
		if (length == 1) return nums[0] == target ? 0 : -1;
		int left = 0, right = length - 1, mid = (left + right) / 2;

		//这个不行
		/*while (left < right) {
			if (nums[mid] == target) return mid;
			if (nums[mid] > nums[left]) {
				if (target > nums[mid]) left = mid;
				else {
					if (target >= nums[left]) right = mid;
					else left = mid;
				}
			}
			else {
				if (target < nums[mid]) right = mid;
				else {
					if (target >= nums[left]) right = mid;
					else left = mid;
				}
			}
			mid = (left + right) / 2;
		}*/

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[left] <= nums[mid]) {
				if (nums[left] <= target && target <= nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if (nums[mid] <= target && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
		return -1;
	} 
};