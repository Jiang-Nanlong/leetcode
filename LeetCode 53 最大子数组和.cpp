#include <iostream>
#include <vector>
using namespace std;

//����һ�����飬�ҳ������о������͵�����������
//�ֲ����ţ���������Ϊ����ʱ���ʹ���һ�������¿�ʼ����Ϊ����ֻ������������
//�ֲ������˳�ȫ�����ţ����Կ���ʹ��̰��
//���ǲ��������Ҳ�������Ĺؼ���һ����û����������ǿ��������������

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int result = INT_MIN;
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			count += nums[i];
			if (count > result)  //����ط�Ӧ���ȱ�������Ȼ�����ж�count�ǲ���<=0����Ϊnums�����п���ȫ�Ǹ�����
				//����������ж�д���ˣ��ͻ�����Ϊ0��Ȼ���ٱ�������Ȼ��ͳ�����
				result = count;

			if (count <= 0) {
				count = 0;
			}

		}
		return result;
	}
};

void main() {
	Solution st;
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	cout << st.maxSubArray(nums) << endl;
}