#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给定一个数组，一开始数组的下标都没有被标记，可以执行任意次以下操作：
// 选择两个互不相同且未标记的下标i和j，满足2*nums[i] <= nums[j]，标记下标i和j
// 执行上述操作任意次，返回nums中最多可以被标记的下标数目

class Solution {
public:
	int maxNumOfMarkedIndices(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int left = n / 2 - 1, right = n - 1;
		int res = 0;
		while (left >= 0) {
			if (nums[left] * 2 <= nums[right]) {
				res += 2;
				right--;
				left--;
			}
			else {
				left--;
			}
		}
		return res;
	}

	// 贪心的来想，数组的前k个和最后k个可以组成小于等于k对数对，且数对的数量和k之间成正比，也就是k越多，数对也会越多。
	// 呈现一个单调关系，那么可以用二分做
	int maxNumOfMarkedIndices1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		auto check = [&](int k) {
			for (int i = 0; i < k; i++) {
				if (2 * nums[i] > nums[i + n - k])
					return false;
			}
			return true;
			};

		int left = 0, right = n / 2 + 1;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (check(mid))
				left = mid;
			else
				right = mid;
		}
		return left * 2;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 9,2,5,4 };
	cout << st.maxNumOfMarkedIndices(nums) << endl;
	cout << st.maxNumOfMarkedIndices1(nums) << endl;
	return 0;
}