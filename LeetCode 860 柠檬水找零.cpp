/*
ÿ������ˮ5Ԫ���˿��Ŷӹ���ÿ����һ��������֧��5Ԫ��10Ԫ��20Ԫ��Ҫ��û�����㣬�ʼ��ͷû��Ǯ��
�������ȷ���㷵��true�����򷵻�false
*/
#include<iostream>
#include <vector>
using namespace std;

//���Լ����뷨����Ϊֻ�����յ�5��10��20��������ֵ����Ǯ��ʱ��ֻ������0��5��15���֣������漰20Ԫ��������������������ͳ��5Ԫ��10Ԫ��ֵ��Ǯ����
//����Ҫ��15Ԫʱ������10+5�����еĻ�����5+5+5
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int count5 = 0, count10 = 0;
		for (int i = 0; i < bills.size(); i++) {
			if (bills[i] == 5) {
				count5++;
			}
			else if (bills[i] == 10) {
				if (--count5 < 0) 
					return false;
				else
					count10++;
			}
			else {
				if (count10 > 0 && count5 > 0) {
					count10--;
					count5--;
				}
				else {
					count5 -= 3;
					if (count5 < 0)
						return false;
				}
			}
		}
		return true;
	}
};
//�꣬�𰸸��ҵ�˼·һ����̰�ĵ�˼�������ڸ�20��Ǯ��Ǯ��ʱ������10+5�������Ļ�����5+5+5
int main() {
	vector<int> bills1 = { 5,5,5,10,20 };
	vector<int> bills2 = { 5,5,10,10,20 };
	vector<int> bills3 = { 10,10 };
	vector<int> bills4 = { 5,5,10 };
	Solution s;
	cout << s.lemonadeChange(bills1) << endl;
	cout << s.lemonadeChange(bills2) << endl;
	cout << s.lemonadeChange(bills3) << endl;
	cout << s.lemonadeChange(bills4) << endl;
	return 0;
}