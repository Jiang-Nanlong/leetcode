#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这个题是要给定一个正整数k，然后把数组中的某一元素或者多个元素翻转共k次，获得最大数组和
//我想着先把数组从小到大排序，然后数组中的数小于0时就翻转，这样的就把绝对值比较大的数都翻转了
//如果负数都翻转完，k还大于0，且k为偶数，那直接返回数组和，如果k是奇数，那就重新排列一次，把当前最小的数翻转一下，然后sum减去它的二倍
//因为之前是按正数加的，但其实应该减去它，所以中间就相差了两倍的它

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (k > 0 && nums[i] <= 0) {
				nums[i] = -nums[i];
				k--;
			}
			sum += nums[i];
		}
		if (k % 2 == 0) return sum;
		else {
			sort(nums.begin(), nums.end());
			return sum - 2 * nums[0];
		}
	}

	//代码随想录的代码，他这个只排列一次，但是排列是按着绝对值从大到小的顺序，这样的话如果k还有剩余，只需要减去数组最后一个就行
	int largestSumAfterKNegations1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), cmp);
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (k > 0 && nums[i] <= 0) {
				nums[i] = -nums[i];
				k--;
			}
			sum += nums[i];
		}
		if (k % 2 == 0) return sum;
		else return sum - 2 * nums[nums.size() - 1];

	}
	static bool cmp(int a, int b) {
		return abs(a) > abs(b);
	}
};

int main() {
	Solution st;
	vector<int> nums{ 3,-1,0,2 };
	int sum = st.largestSumAfterKNegations(nums, 3);
	cout << sum << endl;
	sum = st.largestSumAfterKNegations1(nums, 3);
	cout << sum << endl;
	return 0;
}
