#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* �����ĸ��ȳ������飬�ҳ��ж�������Ϸ�ʽʹ���ĸ������е�Ԫ�ؼ�һ�����0��
* ��������������һ��ͷ��Ҳû�У�Ҳû�뵽�͹�ϣ������ʲô��ϵ�����˴𰸲�֪����
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

	//�ڶ���������û��������ô��
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

	// ���������ˣ�����û�������
	int fourSumCount2(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
		vector<int>& nums4) {
		unordered_map<int, int> umap;
		for (int& i : nums1)
			for (int& j : nums2)
				umap[i + j]++;

		int res = 0;
		for (int& i : nums3)
			for (int& j : nums4)
				if (umap.find(0 - i - j) != umap.end())
					res += umap[-i - j];

		return res;
	}
};

int main() {
	Solution st;
	vector<int> nums1{ 1,2 }, nums2{ -2,-1 }, nums3{ -1,2 }, nums4{ 0,2 };
	int res = st.fourSumCount(nums1, nums2, nums3, nums4);
	cout << res << endl;
	return 0;
}