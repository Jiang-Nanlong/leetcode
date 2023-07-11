/*
每杯柠檬水5元，顾客排队购买，每人买一杯，可能支付5元、10元和20元，要给没人找零，最开始手头没有钱，
如果能正确找零返回true，否则返回false
*/
#include<iostream>
#include <vector>
using namespace std;

//我自己的想法：因为只可能收到5、10、20，三种面值，找钱的时候只可能是0、5、15三种，不会涉及20元，所以想声明两个变量统计5元和10元面值的钱数，
//在需要找15元时优先找10+5，不行的话再找5+5+5
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
//嚓，答案跟我的思路一样，贪心的思想体现在给20块钱找钱的时候，先用10+5，不够的话再用5+5+5
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