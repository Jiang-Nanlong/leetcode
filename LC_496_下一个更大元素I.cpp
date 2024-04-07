#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

//给定两个数组nums1和nums2，nums1是nums2的子集，找出nums1[i]在nums2中对应的第一个大的元素，最后返回数组res，res[i]是num1[i]在nums2数组中第一个比nums1[i]大的值

class Solution {
public:

	//这是我自己写的代码
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> ump;
		stack<int> stk;
		vector<int> temp(nums2.size(), -1), res(nums1.size(), 0);
		for (int i = 0; i < nums2.size(); i++)
			ump.insert({ nums2[i],i });

		for (int i = 0; i < nums2.size(); i++) {
			while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
				temp[stk.top()] = nums2[i];
				stk.pop();
			}
			stk.push(i);
		}

		for (int i = 0; i < nums1.size(); i++) {
			res[i] = temp[ump[nums1[i]]];
		}
		return res;
	}

	//下边是代码随想录的代码，感觉他这个更好，因为nums1是nums2的子集，可能二者的长度差距比较大，并不一定都要把nums2的第一个更大元素求出来
	vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> ump;
		stack<int> stk;
		vector<int> res(nums1.size(), -1);
		for (int i = 0; i < nums1.size(); i++) {
			ump[nums1[i]] = i;
		}
		for (int i = 0; i < nums2.size(); i++) {
			while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
				if (ump.count(nums2[stk.top()]) > 0) {
					res[ump[nums2[stk.top()]]] = nums2[i];
				}
				stk.pop();
			}
			stk.push(i);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums1 = { 4, 1, 2 }, nums2 = { 1, 3, 4, 2 };
	vector<int> res = st.nextGreaterElement(nums1, nums2);
	for (auto i : res)
		cout << i << "  ";

	cout << endl;
	vector<int> res1 = st.nextGreaterElement1(nums1, nums2);
	for (auto i : res1)
		cout << i << "  ";
	return 0;
}
