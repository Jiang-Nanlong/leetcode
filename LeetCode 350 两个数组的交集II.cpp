#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
* ��ĿҪ���ҳ���������Ľ�������κ�349�ⲻһ�������Ҫ�����е����ݱ����ԭ�����е����ָ�����ͬ
*/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		/*
		unordered_multiset<int> umset;    //�������Լ�д�ģ�������unordered_multiset����������������������nums1�е�ÿ����ĸ�ĸ���
		int hash[1001] = {0};
		for(auto &c:nums1) hash[c]++;
		for(auto &c:nums2){
			if(hash[c]-->0)
				umset.insert(c);
		}
		return vector<int>(umset.begin(),umset.end());
		*/
		vector<int> res;
		unordered_map<int, int> ump;       //���Ǳ��˵Ĵ��룬��vector��������unordered_map����nums1�е�ÿ���ַ��ĸ�������ʵҲ���������飬�����ʱ������һЩ��
		//int hash[1001] = {0};  //���������鱣��nums1�е�ÿ���ַ����ֵĴ�����Ч������
		for (auto& c : nums1) ump[c]++;
		for (auto& c : nums2) {
			if (ump[c]-- > 0)
				res.emplace_back(c);
		}
		return res;
	}

	//�ڶ�����
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