#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//三数之和等于0，返回三个数分别是什么，而且每个三元组不能重复
//这个题可以用哈希表做，不过时间太慢了，还是得用双指针做比较快。

class Solution {
public:
	//vector<vector<int>> threeSum(vector<int>& nums) {
	//	vector<vector<int>> res;
	//	sort(nums.begin(), nums.end());
	//	for (int i = 0; i < nums.size(); i++) {
	//		if (nums[i] > 0) break;
	//		if (i > 0 && nums[i] == nums[i - 1]) continue;
	//		unordered_set<int> uset;
	//		for (int j = i + 1; j < nums.size(); j++) {
	//			if (j > i + 2 && nums[j] == nums[j - 1]) continue;   //这里我一直想不通为啥不是j>i+1，调试以后才知道，刚进循环的时候j=i+1,如果当前这个j是结果中的数的话，那他就是第二个。如果写成j>i+1的话，到第三个数就continue了，永远凑不齐三个数
	//			//所以这里只能是j>i+2
	//			int c = 0 - nums[i] - nums[j];
	//			if (uset.find(c) != uset.end()) {
	//				res.push_back({ nums[i],nums[j],c });
	//				uset.erase(c);
	//			}
	//			else {
	//				uset.insert(nums[j]);
	//			}
	//		}
	//	}
	//	return res;
	//}

	//上边的使用哈希表实现的，下边这是用双指针实现的，而且双指针的思路更简单
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>  res;
		int length = nums.size();
		sort(nums.begin(), nums.end());
		for (int k = 0; k < length - 2; k++) {
			if (nums[k] > 0) break;
			if (k > 0 && nums[k] == nums[k - 1]) continue; //不能使用nums[k] == nums[k+1]代替这里的整个条件，如果遇到{-1，-1,2}这种，就会报错
			int i = k + 1, j = length - 1;
			while (i < j) {
				int sum = nums[k] + nums[i] + nums[j];
				if (sum == 0) {
					res.push_back({ nums[k],nums[i],nums[j] });
					while (i < j && nums[i] == nums[++i]);
					while (i < j && nums[j] == nums[--j]);
				}
				else if (sum < 0) {
					while (i < j && nums[i] == nums[++i]);
				}
				else if (sum > 0) {
					while (i < j && nums[j] == nums[--j]);
				}
			}
		}
		return res;
	}

	//第二回做，开始是用的哈希表，在哈希表中找0-a-b，但是这个方法去重困难，然后就用双指针来做了。
	vector<vector<int>> threeSum1(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] > 0)
				break;
			int left = i + 1, right = nums.size() - 1;
			while (left < right) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					res.push_back({ nums[i], nums[left], nums[right] });
					while (left < right && nums[left] == nums[++left]);
					while (left < right && nums[right] == nums[--right]);
				}
				else if (sum < 0) {
					while (left < right && nums[left] == nums[++left])
						;
				}
				else {
					while (left < right && nums[right] == nums[--right])
						;
				}
			}
		}
		return res;
	}

	// 第三次做了
	vector<vector<int>> threeSum2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() - 2; i++) {
			int j = i + 1, k = nums.size() - 1;
			if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
				break;
			if (nums[i] + nums[k - 1] + nums[k] < 0)
				continue;
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				/*if (sum == 0) {
					res.push_back({ nums[i], nums[j], nums[k] });

					while (j<k&&nums[j] == nums[++j]);

					while (j<k&&nums[k] == nums[--k]);

				}
				else if (sum < 0)
					j++;
				else if (sum > 0)
					k--;*/
				if (sum == 0) {
					res.push_back({ nums[i], nums[j], nums[k] });

					while (j < k && nums[j] == nums[j + 1]) j++;  // 这几个while循环里的j<k是必须的，因为nums可能为{0,0,0}这种，在调整j和k时可能会越界。其实用j<nums.size()-1和k>=1来限制也行，但是不如j<k简洁
					j++;
					while (j < k && nums[k] == nums[k - 1]) k--;
					k--;
				}
				else if (sum < 0) {
					while (j < k && nums[j] == nums[j + 1]) j++;
					j++;
				}
				else if (sum > 0) {
					while (j < k && nums[k] == nums[k - 1]) k--;
					k--;
				}
			}
		}
		return res;
	}
};




int main() {
	Solution st;
	vector<int> nums{ -1,-1,2,1 };
	vector<vector<int>> res = st.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	res.clear();
	vector<int> nums1{ -1,0,1,2,-1,-4 };
	res = st.threeSum1(nums1);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	res.clear();
	vector<int> nums2{ -1,0,1,2,-1,-4 };
	res = st.threeSum2(nums2);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}