#include <iostream>
#include <vector>
using namespace std;

//�����е�ÿ��Ԫ�ر�ʾ��ǰλ���������������롣
//�Ҽǵ��ϴ���������û�����ʱզ��̰�ĵģ���λ���û����������Ĵ�������¼����Ƶ��֪����
//�о�̰�ĵ��������
//����ⲻ����ÿһ���ڵ���ô����ֻ���ĵ�ǰ�����������Χ��ֻҪ�����Χ�ڣ������ҵ�·������ȥ��
//��һ����Ҳֻ���ڵ�ǰ�����Χ����Ծ��������Χ�ܸ����յ㣬��˵����������ĩβ

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1) return true;
		int cover = 0;
		for (int i = 0; i <= cover; i++) {
			cover = max(cover, i + nums[i]);
			if (cover >= nums.size() - 1) return true;
		}
		return false;
	}
};

void main() {
	Solution st;
	vector<int> nums{ 2,3,1,1,4 };
	cout << boolalpha << st.canJump(nums) << noboolalpha << endl;
}