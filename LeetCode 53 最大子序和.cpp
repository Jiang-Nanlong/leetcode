/*
����һ����������nums���ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������غ͵����ֵ
*/
#include <iostream>
#include <vector>
using namespace std;

//֮ǰ�ö�̬�滮����������ѧ�˶�̬�滮����������򵥣���������̰����һ�£�̰�����Ļ��������ǰ�����к�Ϊ�����ˣ���ô����ֹ������һ������ʼ���¼���
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int m = nums.size();
		int result = INT_MIN, count = 0;
		for (int i = 0; i < m; i++) {
			count += nums[i];
			if (count > result)
				result = count;
			if (count < 0) count = 0;
		}
		return result;
	}
};

int main() {
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	Solution s;
	cout << s.maxSubArray(nums) << endl;
	return 0;
}