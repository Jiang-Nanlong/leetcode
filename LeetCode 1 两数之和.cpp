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