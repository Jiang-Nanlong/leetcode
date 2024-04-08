#include <iostream>
#include <vector>
using namespace std;

//分三种情况：1.给五块钱只接受下；2.给十块钱找五块；3.给二十，优先找回十块+五块，不行的话再找三张五块。

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int count[2] = { 0 };   //收集五块或十块的钱数
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
};

int main() {
	Solution st;
	vector<int> bills{ 5,5,5,10,20 };
	cout << boolalpha << st.lemonadeChange(bills) << noboolalpha << endl;
	return 0;
}
