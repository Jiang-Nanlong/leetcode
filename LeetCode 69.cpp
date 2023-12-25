#include <iostream>
using namespace std;


/*
* ��Ϊ������ǳ����ڶ��ֲ��ҵ���һ�ڣ����������ö��ֲ�����������һ��ʼ��������һֱ����2�����ҵ���һ��ƽ��������x������Ȼ���ٴ�x+1����ѭ�����ҵ���һ��ƽ������x������Ȼ���һ���ء�
* �������˱��˵Ĵ����֪����ô�š�
* ������ʧ��ʱ����ʱ��left��λ�þ��ǵ�һ��ƽ������x������������ƽ����Ӧ����right��left�м䡣
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