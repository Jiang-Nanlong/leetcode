#include <iostream>
#include <vector>
using namespace std;

//�о���������ѣ��벻���ף���Ծ��Ϸ����ֻҪ�ж��ܷ񵽴��յ���У������Ҫ�ҵ������յ���С��Ҫ����
//�ҿ�ʼ����ǣ�����Ǹ��Ƿ�Χ�����ı䣬������+1�����ǲ��ԡ�
//�о�������������̨�ױȽϺ���ͨ��һ��̨�׾��൱�ڵ�ǰ���Ƿ�Χ���ܴﵽ�ĵط���ͬʱ��ǰ̨�׵Ĳ�ͬλ��Ҳ��ı���һ��̨�����ܵ������Զλ�ã�
//�����ǰ̨���ߵ�ͷ�ˣ������ܵ����յ㣬��ֻ�ܵ���һ��̨�׼����ظ�������̣�ֱ���յ���ĳһ��̨���ϣ����̨����������С����Ծ������
//������Ҳ�Ǹ��ݴ𰸷��Ƶģ�Ҫ�������Լ��룬�һ����벻ͨ��

class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int curcover = 0, nextcover = 0;
		int count = 0;
		for (int i = 0; i <= nums.size(); i++) {
			nextcover = max(i + nums[i], nextcover);
			if (i == curcover) {
				count++;
				curcover = nextcover;
				if (nextcover >= nums.size() - 1)
					break;
			}

		}
		return count;
	}

	//�о��±ߵĴ���������
	int jump1(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		int curcover = 0, nextcover = 0;
		int count = 0;
		for (int i = 0; i <= nums.size(); i++) {
			nextcover = max(i + nums[i], nextcover);
			if (i == curcover) {  //���ﵱǰ̨�׵�ĩβ
				if (curcover != nums.size() - 1) {  //�����ǰҲ�����յ�
					count++;
					curcover = nextcover;
					if (nextcover >= nums.size() - 1) //�����һ��̨�׿��Ե��յ�
						break;
				}
				else  //�����ǰ�Ѿ����յ���
					break;
			}

		}
		return count;
	}
};

int main() {
	Solution st;
	vector<int> nums{ 2,3,1,1,4 };
	int res = st.jump1(nums);
	cout << res << endl;
	return 0;
}