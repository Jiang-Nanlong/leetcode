/*
�������������֮��Ĳ��ϸ���������͸���֮�佻�棬����������Ϊ�ڶ����С���һ����(������ڵĻ�)�������������߸�����
������һ��Ԫ�ػ�����������Ԫ�ص�����Ҳ��Ϊ�ڶ����С������п�ͨ����ԭʼ������ɾ��һЩ��Ҳ�ɲ�ɾ����Ԫ������ã�ʣ�µ�Ԫ�ر���ԭʼ˳��
����ԭʼ�����аڶ����е�������еĳ��ȣ�ע���ڶ�������ԭʼ�����п��Բ�������
*/
#include <iostream>
#include <vector>
using namespace std;

//��Ŀ�С��������������֮��Ĳ��ϸ��������͸���֮�佻�棬����������Ϊ�ڶ����С���������Ϊ�ж����������ǰһ����ͺ�һ������ž���
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int m = nums.size();
		if (m < 2) return m;  //m=0��1
		int preDiff = 0, curDiff = 0, result = 1;  //������ֻ���������־����ӣ�����ߵĵ�һ�������Զ��������ڣ�������ʼresult=1�����ѭ�������ұ߽��ǰһ��
		for (int i = 0; i < m - 1; i++) {
			curDiff = nums[i + 1] - nums[i];
			if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
				preDiff = curDiff;
				result++;
			}
		}
		return result;
	}
};

int main() {
	vector<int> nums1 = { 1,7,4,9,2,5 };
	vector<int> nums2 = { 1,17,5,10,13,15,10,5,16,8 };
	vector<int> nums3 = { 1,2,3,4,5,6,7,8,9 };
	Solution s;
	cout << s.wiggleMaxLength(nums1) << endl;
	cout << s.wiggleMaxLength(nums2) << endl;
	cout << s.wiggleMaxLength(nums3) << endl;

	return 0;
}