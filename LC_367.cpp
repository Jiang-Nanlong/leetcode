#include <iostream>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int left = 0, right = num;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if ((unsigned long long)mid * mid > num)
				right = mid - 1;
			else if ((unsigned long long) mid * mid < num)
				left = mid + 1;
			else
				return true;
		}
		return false;
	}
};

int main() {
	Solution s;
	int x = s.isPerfectSquare(16);
	cout << boolalpha << x << noboolalpha << endl;
	return 0;
}
