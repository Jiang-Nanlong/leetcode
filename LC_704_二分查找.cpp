#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target < nums[mid])
				right = mid - 1;
			else if (target > nums[mid])
				left = mid + 1;
			else
				return mid;
		}
		return -1;
	}
};

int main() {
	Solution st;
	vector<int> nums{ -1,0,3,5,9,12 };
	int target = 9;
	cout << st.search(nums, target) << endl;
	return 0;
}
