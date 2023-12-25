#include <iostream>
using namespace std;


/*
* 因为这个题是出现在二分查找的那一节，所以想着用二分查找做，所以一开始就想着先一直除以2，先找到第一个平方不大于x的数，然后再从x+1往后循环，找到第一个平方大于x的数，然后减一返回。
* 后来看了别人的代码才知道怎么着。
* 当查找失败时，这时候left的位置就是第一个平方大于x的数，真正的平方根应该在right和left中间。
*
*
*/

class Solution {
public:
	/*
		int mySqrt(int x) {
			unsigned long long y2, y=x;
			do{
				y/=2;
				y2 = y*y;
			}while(y2 > y);
			for(;y*y<=x;y++);
			return --y;
		}
	*/
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if ((unsigned long long) mid * mid > x)
				right = mid - 1;
			else if ((unsigned long long)mid * mid < x)
				left = mid + 1;
			else
				return mid;
		}
		return left - 1;
	}
};


int main() {
	Solution s;
	int res = s.mySqrt(8);
	cout << res << endl;
}