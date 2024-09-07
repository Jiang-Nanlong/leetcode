#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组，求出每一个长度为k的子数组的美丽值。这里对美丽值的定义是如果子数组中的第x小元素是负数，那么美丽值就是这个元素值，否则为0。
// 返回所有子数组的美丽值。

// 因为这里的nums[i]的数据范围为[-50, 50]，所以在找第x小元素的时候直接使用暴力的做法。

class Solution {
public:
	vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
		vector<int> cnt(101, 0);  // 统计子串中每一个元素的出现次数，把负数都映射到正数范围
		int n = nums.size();
		vector<int> res(n - k + 1, 0);
		for (int i = 0; i < k - 1; i++) {
			++cnt[nums[i] + 50];
		}
		for (int i = k - 1; i < n; i++) {
			++cnt[nums[i] + 50];
			if (i >= k)
				--cnt[nums[i - k] + 50];

			int count = x;
			for (int j = 0; j < 50; j++) {
				count -= cnt[j];
				if (count <= 0) { // 找到第x小元素
					res[i - k + 1] = j - 50;
					break;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ -3,1,2,-3,0,-3 };
	int k = 2, x = 1;
	vector<int> res = st.getSubarrayBeauty(nums, k, x);
	for (int i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}