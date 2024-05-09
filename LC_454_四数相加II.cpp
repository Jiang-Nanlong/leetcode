#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* 给出四个等长的数组，找出有多少种组合方式使得四个数组中的元素加一块等于0。
* 刚做这个题真的是一点头绪也没有，也没想到和哈希表能有什么联系。看了答案才知道。
*/

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> ump;
		for (int& a : nums1)
			for (int& b : nums2)
				ump[a + b]++;
		int count = 0;
		for (int& c : nums3)
			for (int& d : nums4)
				if (ump.find(0 - (c + d)) != ump.end())
					count += ump[0 - (c + d)];
		return count;
	}

	//第二回做，真没想起来怎么做
	int fourSumCount1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
		vector<int>& nums4) {
		unordered_map<int, int> umap;
		int count = 0;
		for (int& a : nums1)
			for (int& b : nums2)
				umap[a + b]++;

		for (int& c : nums3)
			for (int& d : nums4) {
				auto it = umap.find(0 - (c + d));
				if (it != umap.end()) {
					count += it->second;
				}
			}

		return count;
	}
};

int main() {
	Solution st;
	vector<int> nums1{ 1,2 }, nums2{ -2,-1 }, nums3{ -1,2 }, nums4{ 0,2 };
	int res = st.fourSumCount(nums1, nums2, nums3, nums4);
	cout << res << endl;
	return 0;
}
