#include <iostream>
using namespace std;

//做过LeetCode 69 x的平方根那题之后，这个题就很简单了

class Solution {
public:
	bool isPerfectSquare(int num) {
		int left = 0, right = num;
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			long long product = mid * mid;
			if (num > product)
				left = mid + 1;
			else if (num < product)
				right = mid - 1;
			else
				return true;
		}
		return false;
	}
};

int main() {
	Solution st;
	cout << boolalpha << st.isPerfectSquare(16) << noboolalpha << endl;
	return 0;
}