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
};

void main() {
	Solution st;
	vector<int> nums{ 0,1,0,3,12 };
	st.moveZeroes(nums);
	for (auto c : nums)
		cout << c << " ";
	cout << endl;
	cout << __cplusplus << endl;
	cout << _MSVC_LANG << endl;
}