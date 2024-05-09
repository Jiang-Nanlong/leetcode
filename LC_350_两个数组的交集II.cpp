#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* 题目要求找出两个数组的交集，这次和349题不一样，这回要求结果中的数据必须跟原数组中的数字个数相同
*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		/*
		unordered_multiset<int> umset;    //这是我自己写的，想着用unordered_multiset来保存结果，用数组来保存nums1中的每个字母的个数
		int hash[1001] = {0};
		for(auto &c:nums1) hash[c]++;
		for(auto &c:nums2){
			if(hash[c]-->0)
				umset.insert(c);
		}
		return vector<int>(umset.begin(),umset.end());
		*/
		vector<int> res;
		unordered_map<int, int> ump;       //这是别人的代码，用vector保存结果，unordered_map保存nums1中的每个字符的个数，其实也可以用数组，数组的时间会更短一些。
		//int hash[1001] = {0};  //可以用数组保存nums1中的每个字符出现的次数，效果更好
		for (auto& c : nums1) ump[c]++;
		for (auto& c : nums2) {
			if (ump[c]-- > 0)
				res.emplace_back(c);
		}
		return res;
	}

	//第二次做
	vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> umap;
		for (int& i : nums1)
			umap[i]++;

		for (int& i : nums2) {
			if (--umap[i] >= 0)
				res.push_back(i);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums1{ 1,2,2,1 }, nums2{ 2,2 };
	vector<int> res = st.intersect(nums1, nums2);
	for (auto& c : res)
		cout << c << " ";
	cout << endl;
	return 0;
}
