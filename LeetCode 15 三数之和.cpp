#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//三数之和等于0，返回三个数分别是什么，而且每个三元组不能重复
//这个题可以用哈希表做，不过时间太慢了，还是得用双指针做比较快。

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			unordered_set<int> uset;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 2 && nums[j] == nums[j - 1]) continue;   //这里我一直想不通为啥不是j>i+1，调试以后才知道，刚进循环的时候j=i+1,如果当前这个j是结果中的数的话，那他就是第二个。如果写成j>i+1的话，到第三个数就continue了，永远凑不齐三个数
				//所以这里只能是j>i+2
				int c = 0 - nums[i] - nums[j];
				if (uset.find(c) != uset.end()) {
					res.push_back({ nums[i],nums[j],c });
					uset.erase(c);
				}
				else {
					uset.insert(nums[j]);
				}
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 0,0,0,0 };
	vector<vector<int>> res = st.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}