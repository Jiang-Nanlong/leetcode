#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//这个题思路还是挺简单的，剪枝一开始没想到
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int length = nums.size();
		if (length < 4) return{};
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < length - 3; i++) {
			//if(nums[i]>=target) break;  开始想的剪枝，但是遇到{0,0,0,0} target=0的情况就会报错了
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;  //开始没想到这个剪枝，运行时间有点长
			if ((long)nums[i] + nums[length - 1] + nums[length - 2] + nums[length - 3] < target) continue;  //开始没想到这个剪枝，运行时间有点长
			for (int j = i + 1; j < length - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;   //开始没想到这个剪枝，运行时间有点长
				if ((long)nums[i] + nums[j] + nums[length - 1] + nums[length - 2] < target) continue;      //开始没想到这个剪枝，运行时间有点长
				int left = j + 1, right = length - 1;
				while (left < right) {
					long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						res.push_back({ nums[i],nums[j],nums[left],nums[right] });
						while (left < right && nums[left] == nums[++left]);
						while (left < right && nums[right] == nums[--right]);
					}
					else if (sum < target) {
						while (left < right && nums[left] == nums[++left]);
					}
					else if (sum > target) {
						while (left < right && nums[right] == nums[--right]);
					}
				}
			}
		}
		return res;
	}

	//第二回做，这次的剪枝不如之前的好，运行时间长很多
	vector<vector<int>> fourSum1(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4)
			return res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] > target && nums[i] >= 0)
				break;
			for (int j = i + 1; j < nums.size() - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
					break;
				int left = j + 1, right = nums.size() - 1;
				while (left < right) {
					long long sum =
						(long long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						res.push_back(
							{ nums[i], nums[j], nums[left], nums[right] });
						while (left < right && nums[left] == nums[++left])
							;
						while (left < right && nums[right] == nums[--right])
							;
					}
					else if (sum < target) {
						while (left < right && nums[left] == nums[++left])
							;
					}
					else {
						while (left < right && nums[right] == nums[--right])
							;
					}
				}
			}
		}
		return res;
	}
	//又重新修改过以后，这次运行结果极好
	vector<vector<int>> fourSum2(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int length = nums.size();
		if (length < 4)
			return res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < length - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] >
				target)
				break;
			if ((long long)nums[i] + nums[length - 1] + nums[length - 2] +
				nums[length - 3] <
				target)
				continue;
			for (int j = i + 1; j < length - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] >
					target)
					break;
				if ((long long)nums[i] + nums[j] + nums[length - 1] +
					nums[length - 2] <
					target)
					continue;
				int left = j + 1, right = length - 1;
				while (left < right) {
					long long sum =
						(long long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						res.push_back(
							{ nums[i], nums[j], nums[left], nums[right] });
						while (left < right && nums[left] == nums[++left])
							;
						while (left < right && nums[right] == nums[--right])
							;
					}
					else if (sum < target) {
						while (left < right && nums[left] == nums[++left])
							;
					}
					else {
						while (left < right && nums[right] == nums[--right])
							;
					}
				}
			}
		}
		return res;
	}

	// 第三次做
	vector<vector<int>> fourSum3(vector<int>& nums, int target) {
		if (nums.size() < 4)
			return {};
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<vector<int>> res;
		for (int i = 0; i < len - 3; i++) {
			if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if ((long long)nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target) continue;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < len - 2; j++) {
				if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				if ((long long)nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target) continue;
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1, right = len - 1;
				while (left < right) {
					long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						res.push_back({ nums[i], nums[j], nums[left], nums[right] });
						while (left < right && nums[left] == nums[left + 1]) left++;
						left++;
						while (left < right && nums[right] == nums[right - 1]) right--;
						right--;
					}
					else if (sum < target) {
						while (left < right && nums[left] == nums[left + 1]) left++;
						left++;
					}
					else if (sum > target) {
						while (left < right && nums[right] == nums[right - 1]) right--;
						right--;
					}
				}
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 1,-2,-5,-4,-3,3,3,5 };
	int target = -11;
	vector<vector<int>> res = st.fourSum3(nums, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}