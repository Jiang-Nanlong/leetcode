#include <iostream>
using namespace std;

//����һ������ƽ�������ڶ������ˣ�����û�뵽��ô�ö��ֲ���������

class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left <= right) {
			long long mid = left + (right - left) / 2; //�������longlong����Ϊ�����л���intԽ��
			long long product = mid * mid;
			if (product > x)
				right = mid - 1;
			else if (product < x)
				left = mid + 1;
			else
				return mid;
		}
		return left - 1;   //���ƽ�����Ǹ�С�����Ͳ�����ʾ��������Ȼ��left���ǵ�һ��ƽ������x����������left-1���ǵ�һ��ƽ��С��x����
	}
};

int main() {
	Solution st;
	cout << st.mySqrt(8) << endl;
	return 0;
}