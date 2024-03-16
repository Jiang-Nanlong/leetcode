#include <iostream>
#include <vector>
using namespace std;

//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//��˫ָ��

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int slow = 0, fast = 0;
		for (; fast < nums.size(); fast++) {
			if (nums[fast] != 0)
				nums[slow++] = nums[fast];
		}
		while (slow < nums.size())
			nums[slow++] = 0;
	}

	//�±��ǵڶ������Ĵ���
	void moveZeroes1(vector<int>& nums) {
		int i = 0, j = 0;
		for (; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[j] = nums[i];
				j++;
			}
		}
		while (j < nums.size()) {
			nums[j++] = 0;
		}
	}
};

void main() {
	Solution st;
	vector<int> nums{ 0,1,0,3,12 };
	st.moveZeroes(nums);
	for (auto c : nums)
		cout << c << " ";
	cout << endl;
	vector<int> nums1{ 0,1,0,3,12 };
	st.moveZeroes1(nums1);
	for (auto c : nums1)
		cout << c << " ";
	cout << endl;
	cout << __cplusplus << endl;
	cout << _MSVC_LANG << endl;
}