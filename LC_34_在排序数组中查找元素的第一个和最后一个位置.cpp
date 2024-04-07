#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int index = binarySearch(nums, target);
		if (index == -1)
			return { -1, -1 };
		else {
			int left = index, right = index;
			for (; left >= 0 && nums[left] == target; left--);  //开始的时候这两个for循环的判断条件写反了，也就是先判断是否相等，再判断是否越界了，结果当数组中只有一个元素时就报越界的错误。
			for (; right < nums.size() && nums[right] == target; right++);
			return { left + 1, right - 1 };
		}
	}

	//下边这是第一回做这个题时提交的代码
	vector<int> searchRange1(vector<int>& nums, int target) {
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
	int binarySearch(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > target)
				right = mid - 1;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				return mid;
		}
		return -1;
	}

	vector<int> searchHelper(vector<int>& nums, int target, int i) {
		int left = i, right = i;
		for (; left >= 0 && nums[left] == target; left--);
		for (; right <= nums.size() - 1 && nums[right] == target; right++);
		return vector<int>{++left, --right};
	}
};

int main() {
	Solution st;
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	vector<int> res = st.searchRange(nums, target);
	cout << res[0] << "  " << res[1] << endl;
	vector<int>res1 = st.searchRange1(nums, target);
	cout << res1[0] << "  " << res1[1] << endl;
	return 0;
}
