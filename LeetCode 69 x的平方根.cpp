#include <iostream>
using namespace std;

//计算一个树的平方根，第二遍做了，还是没想到怎么用二分查找来做。

class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left <= right) {
			long long mid = left + (right - left) / 2; //这里设成longlong是因为用例中会有int越界
			long long product = mid * mid;
			if (product > x)
				right = mid - 1;
			else if (product < x)
				left = mid + 1;
			else
				return mid;
		}
		return left - 1;   //如果平方根是个小数，就不会显示出整数，然后left就是第一个平方大于x的数，所以left-1就是第一个平方小于x的数
	}
};

int main() {
	Solution st;
	cout << st.mySqrt(8) << endl;
	return 0;
}