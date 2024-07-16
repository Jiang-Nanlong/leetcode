#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		auto binerysearch = [&]() {
			int left = 0, right = n - 1;
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] < k)
					left = mid + 1;
				else
					right = mid;
			}
				return left;
			};

		int index = binerysearch();
		return index;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,11,10,1,3 };
	int k = 10;
	cout << st.minOperations(nums, k) << endl;
	return 0;
}