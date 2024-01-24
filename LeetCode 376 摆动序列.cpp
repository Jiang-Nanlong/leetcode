#include <iostream>
#include <vector>
using namespace std;

//�������֮��Ĳ��ϸ���������������֣��ͳ������ǰڶ����С���һ�����������Ҳ�����Ǹ�����������Ԫ�ص�����Ҳ�ǰڶ����С�
//���������аڶ������ָ���
//�о�����������ѣ���ֻ���뵽Ҫ��1��2�Ĳ��2��3�Ĳ���бȽϣ�������벻���������������ƽ�¾Ͳ����ˣ�������Ҳ�벻ͨ���������ô��̰�Ľ���ġ�

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int prediff = 0, nextdiff = 0, result = 1;  //result=1��Ĭ�����һ��Ԫ���ǡ�
		//prediff=0�����ڵ�0��֮ǰ����һ���ڵ㣬����ڵ��nums[0]һ����������nums[0]����ڵ����ʹ���±ߵĴ�����
		for (int i = 0; i < nums.size() - 1; i++) {
			nextdiff = nums[i + 1] - nums[i];
			if ((prediff >= 0 && nextdiff < 0) || (prediff <= 0 && nextdiff > 0)) {
				//������ж�����д����������Ҫ����Ϊ������ƽ��ʱ����1,2,2,2,1���ڶ�������3��������д������ͳ�Ƶ���ʵ�������Ǹ�2��
				//��˵Ӧ��Ҳ����ͳ��������Ǹ�2�������Ұ����������Ժ��ǲ��ԣ���֪��Ϊɶ
				result++;
				prediff = nextdiff;  //����ط��е㲻̫��
			}
		}
		return result;
	}
};

//������˵����⻹�����ö�̬�滮������Ժ�ѧ�˶�̬�滮������
//�����Ū�������Ժ����ر���prediff=nextdiff����

void main() {
	Solution st;
	vector<int> nums{ 1,7,4,9,2,5 };
	cout << st.wiggleMaxLength(nums) << endl;
}