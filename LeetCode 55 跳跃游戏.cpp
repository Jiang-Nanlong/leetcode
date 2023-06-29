/*
����һ���Ǹ����飬�ʼ������ĵ�һ��λ�ã����е�ÿ��Ԫ�ش����Ŵӵ�ǰλ�ÿ��������������룬�ж��ܷ��������һ��
*/
#include <iostream>
#include <vector>
using namespace std;

//��Ŀ���ص�Ӧ�÷���ÿ���ƶ����������ķ�Χ�����ؾ���ÿһ�δ��ĸ�λ�ÿ�ʼ��
//�̰꣬���㷨��ô��ô���룬����ʶ�����ĺܺ���⣬��������̫�����ˣ��꣬ÿ��Ҫ�������ܿ���������Ϊ�ܸ��ӵĴ��룬������ȴ�ܼ�
//��
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int count = 0;
		if (nums.size() == 1) return true;
		for (int i = 0; i <= count; i++) {
			count = max(i + nums[i], count);
			if (count >= nums.size() - 1)return true;
		}
		return false;
	}
};

int main() {
	vector<int> nums1 = { 2,3,1,1,4 };
	vector<int> nums2 = { 3,2,1,0,4 };
	Solution s;
	cout << s.canJump(nums1) << endl;
	cout << s.canJump(nums2) << endl;
	return 0;
}