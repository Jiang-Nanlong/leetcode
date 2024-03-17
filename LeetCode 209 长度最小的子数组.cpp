/*
* 209 ������С��������
* ����һ������n���������������������target�����������ҳ������������������⼸�����ĺʹ��ڵ���target�����������鳤�ȵ���Сֵ
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int i = 0, sum = 0, count = 0, result = INT_MAX;  //i��Ϊ�������ڵĿ�ʼλ�ã�sum�Ǵ��ڵ��ܺͣ�count�ǵ�ǰ��������������������ĳ��ȣ�result�����Ľ��
		for (int j = 0; j < nums.size(); j++) {   //j�ǻ������ڵĽ���λ��
			sum += nums[j];
			while (sum >= target) {   //��С����
				count = j - i + 1;
				result = result < count ? result : count;
				sum -= nums[i++];
			}
		}
		return result == INT_MAX ? 0 : result;
	}

	//�ڶ������Ĵ���
	//û�������ǻ������ڵ��⣬����������ʾ�������ˣ�������д�����ʱ��һ�������������ˣ���ʵ��������ģ�������ÿ����С���ں󶼰Ѵ����ڵĽ����Ϊ0�ˣ���ʵҲ���øĵġ�
	int minSubArrayLen1(int target, vector<int>& nums) {
		int sum = 0, res = INT_MAX;
		for (int front = 0, last = 0; front < nums.size(); front++) {
			sum += nums[front];
			if (sum >= target) {
				while (sum >= target) {
					sum -= nums[last];
					last++;
				}
				res = min(res, front - last + 2);
			}
		}
		if (res == INT_MAX)
			return 0;
		return res;
	}
};

//������ǻ������ڵ��⣬��Ϊ�ó�ʱ��û�Ӵ����������ˣ�������֮����Լ�о�Ӧ��������ָ��ѡ��һ����Χ�����ǽ�������ûͷ����
//Ȼ��ֱ�ӿ��˴𰸣���֪��զ��

int main() {
	Solution st;
	vector<int> nums{ 2,3,1,2,4,3 };
	int res = st.minSubArrayLen(7, nums);
	cout << res << endl;
	cout << st.minSubArrayLen1(7, nums) << endl;
	return 0;
}