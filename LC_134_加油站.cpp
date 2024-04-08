#include <iostream>
#include <vector>
using namespace std;

//��������뵽��gas��cost����Ķ�Ӧλ����������ÿ������վ�����ľ����档������еľ������һ��С��0��˵�������ܿ�һȦ��
//���Ǵ��ĸ�λ�ÿ�ʼ���һ���ֻ���뵽�ñ����Ľⷨ���Ӹ���λ��ѭ��һ�飬Ȼ�����ÿ��λ�õľ�����������ܵ�����ʼλ�õ�ǰһ��˵�����Կ�һȦ�������ܡ�
//���ǿ���һ�´�������¼��pdf��˵��һ��ʱ�临�Ӷ�O(n)�ķ���������һ�����벻����
//Ȼ������Ƶ��֪����������˼Ҳ����ÿ��λ�õľ������������0��ĳ����ʱ����������Ϊ������˵���������ѡ���κ�һ��λ����Ϊ��㶼����ͣ�
//Ȼ��ʹӵ�ǰ�ڵ����һ��λ�����¿�ʼ���㡣
//����ľֲ������ǵ�ĳ�㴦�ľ�����С��0ʱ����ʼλ��������i+1����Ϊi֮ǰ��ʼ�Ķ����С�
//ȫ�����ž����ҵ�һ��������һȦ��λ�á�
//��������������Լ��룬�ҿ϶������벻�������������ҪһЩ��ѧ֤��

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int cursum = 0, totalsum = 0, start = 0;
		for (int i = 0; i < gas.size(); i++) {
			cursum += gas[i] - cost[i];
			totalsum += gas[i] - cost[i];
			if (cursum < 0) {
				start = i + 1;   //Ϊʲô���ﲻд��start=i��Ȼ����󷵻�start+1����Ϊ�п���0����������ʼλ�ã��������̶������漰�޸������¡�
				cursum = 0;
			}
		}
		if (totalsum < 0) return -1;
		return start;
	}

	//�ڶ�����������û�����������������Ѿ���Щ������˼·��
	//����˵���һ�������ڵ�rest[i]�ĺ���С��0�Ļ�����������ڵ����е㶼�ǲ�����Ϊ���ģ���Ϊ�κ�һ������Ϊ����ߵ�����ĩ�˵�ʱ����������С��0��
	//�������ֻ������һ��������
	int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
		int curSum = 0;
		int totalSum = 0;  //��������������·�̵ľ������Ƿ����0
		int start = 0;
		for (int i = 0; i < gas.size(); i++) {
			curSum += gas[i] - cost[i];
			totalSum += gas[i] - cost[i];
			if (curSum < 0) {
				start = i + 1;
				curSum = 0;
			}
		}
		if (totalSum < 0) return -1;
		return start;
	}
};

int main() {
	Solution st;
	vector<int> gas{ 3,1,1 }, cost{ 1,2,2 };
	cout << st.canCompleteCircuit(gas, cost) << endl;
	return 0;
}