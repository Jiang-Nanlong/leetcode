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

public:
	// 第三次做，开始的时候没注意到要用0(logn)的时间复杂度解决
	vector<int> searchRange2(vector<int>& nums, int target) {
		vector<int> res(2, 0);
		bool firstappear = false;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				if (firstappear == false) {
					res[0] = i;
					res[1] = i;
					firstappear = true;
				}
				else
					res[1] = i;
			}
		}
		if (firstappear)
			return res;
		return { -1, -1 };
	}

	//用二分查找做
	vector<int> searchRange3(vector<int>& nums, int target) {
		int mid = binarySearch3(nums, target);
		if (mid == -1)
			return { -1, -1 };
		vector<int> res(2, mid);
		int left = mid, right = mid;
		while (left >= 0 && nums[left] == target) {
			res[0] = left--;
		}
		while (right < nums.size() && nums[right] == target) {
			res[1] = right++;
		}
		return res;
	}

	int binarySearch3(vector<int>& nums, int target) {
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
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	vector<int> res = st.searchRange(nums, target);
	cout << res[0] << "  " << res[1] << endl;
	vector<int>res1 = st.searchRange1(nums, target);
	cout << res1[0] << "  " << res1[1] << endl;
	vector<int> res2 = st.searchRange2(nums, target);
	cout << res2[0] << "  " << res2[1] << endl;
	vector<int>res3 = st.searchRange3(nums, target);
	cout << res3[0] << "  " << res3[1] << endl;
	return 0;
}