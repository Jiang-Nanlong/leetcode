#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//题目中有一个假设是只会存在一个有效答案

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> ump;
		int difference = 0, i = 0;
		for (; i < nums.size(); i++) {
			difference = target - nums[i];
			if (ump.find(difference) != ump.end())
				return { ump[difference],i };
			else
				ump[nums[i]] = i;
		}
		return {};
	}

	//第二次做，这次写了两个for循环，不如第一次写的简洁了。时间复杂度O(n)
	vector<int> twoSum1(vector<int>& nums, int target) {
		//vector<int> res;
		unordered_map<int, int> umap;
		for (int i = 0; i < nums.size(); i++) {
			umap[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			auto it = umap.find(target - nums[i]);
			if (it != umap.end() && it->second != i) {
				/*res.push_back(i);
				res.push_back(it->second);
				return res;*/
				return { i,it->second };
			}
		}
		return {};
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,7,11,15 };
	int target = 9;
	vector<int> res = st.twoSum(nums, target);
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}
