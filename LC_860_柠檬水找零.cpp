#include <iostream>
#include <vector>
using namespace std;

//�����������1.�����Ǯֻ�����£�2.��ʮ��Ǯ����飻3.����ʮ�������һ�ʮ��+��飬���еĻ�����������顣

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int count[2] = { 0 };   //�ռ�����ʮ���Ǯ��
		for (int i = 0; i < bills.size(); i++) {
			if (bills[i] == 5)
				count[0]++;
			else if (bills[i] == 10) {
				if (count[0] <= 0)
					return false;
				count[0]--;
				count[1]++;
			}
			else {
				if (count[1] > 0 && count[0] > 0) {
					count[1]--;
					count[0]--;
				}
				else if (count[0] >= 3) {
					count[0] -= 3;
				}
				else return false;
			}
		}
		return true;
	}

	//�ڶ�����
	bool lemonadeChange1(vector<int>& bills) {
		int count_5 = 0, count_10 = 0;
		for (auto& bill : bills) {
			if (bill == 5)
				count_5++;
			if (bill == 10) {
				if (count_5 == 0) return false;
				count_5--;
				count_10++;
			}
			else if (bill == 20) {
				if (count_10 > 0 && count_5 > 0) {
					count_10--;
					count_5--;
				}
				else if (count_10 == 0 && count_5 >= 3) {
					count_5 -= 3;
				}
				else
					return false;
			}
		}
		return true;
	}
};

int main() {
	Solution st;
	vector<int> bills{ 5,5,5,10,20 };
	cout << boolalpha << st.lemonadeChange(bills) << noboolalpha << endl;
	return 0;
}