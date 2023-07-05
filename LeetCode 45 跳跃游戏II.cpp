/*
��Ծ��Ϸ����һ�β�࣬�������Ҫ���ص����յ���Ҫ����С����
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int curdistance = 0, nextdistance = 0, count = 0;
		int m = nums.size();
		for (int i = 0; i < m - 1; i++) {   //���ﲻ��Ҫ���������һ���㣬ֻ��Ҫ�����������ڶ����ڵ����
			nextdistance = max(nums[i] + i, nextdistance);
			if (i == curdistance) {  //�����ǰ�Ѿ����ﵱǰ��һ�������ߵ�����Զ�ķ�Χ���о������е�������Ĳ����������˼��
				curdistance = nextdistance;
				count++;
			}
		}
		return count;
	}
};
//�о����첻�����������»���������⣬�����е�������е���˼��
int main() {
	vector<int> nums1 = { 2,3,1,1,4 };
	vector<int> nums2 = { 2,3,0,1,4 };
	Solution s;
	cout << s.jump(nums1) << endl;
	cout << s.jump(nums2) << endl;
	return 0;
}