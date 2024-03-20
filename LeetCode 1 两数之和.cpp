#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//��Ŀ����һ��������ֻ�����һ����Ч��

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

	//�ڶ����������д������forѭ���������һ��д�ļ���ˡ�ʱ�临�Ӷ�O(n)
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