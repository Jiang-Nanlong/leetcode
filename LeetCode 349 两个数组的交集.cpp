#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		//ԭ��û˵Ҫ��������,�����������е�ÿһ��Ԫ�ض���Ψһ�ģ������ÿ�����������˳��
		unordered_set<int> uset;
		int a[1001] = { 0 };
		for (auto& c : nums1) a[c] = 1;
		for (auto& c : nums2) {
			if (a[c] == 1)
				uset.insert(c);
		}
		return vector<int>(uset.begin(), uset.end());
	}
};

int main() {
	Solution st;
	vector<int> nums11{ 1,2,2,1 }, nums12{ 2,2 };
	vector<int> nums21{ 4,9,5 }, nums22{ 9,4,9,8,4 };
	vector<int> res1 = st.intersection(nums11, nums12);
	vector<int> res2 = st.intersection(nums21, nums22);
	for (auto& c : res1)
		cout << c << "  ";
	cout << endl;
	for (auto& c : res2)
		cout << c << " ";
	cout << endl;
	return 0;
}