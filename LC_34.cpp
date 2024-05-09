#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				return searchHelper(nums, target, mid);
		}
		return vector<int>{-1, -1};
	}
private:
	vector<int> searchHelper(vector<int>& nums, int target, int i) {
		int left = i, right = i;
		for (; left >= 0 && nums[left] == target; left--);  //最开始的时候把这两个for循环里的条件写反了，写成nums[left] == target && left >= 0了，
		//这样就先判断是不是等于target，如果left小于0，这里就会报错。反过来先判断是不是>=就行了，如果<0就不会继续往后走了 
		for (; right <= nums.size() - 1 && nums[right] == target; right++);
		return vector<int>{++left, --right};
	}
};
int main() {
	Solution st;
	vector<int> nums = { 1 };
	int target = 1;
	vector<int> res = st.searchRange(nums, target);

	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << "  ";
	cout << endl;
	return 0;
}
