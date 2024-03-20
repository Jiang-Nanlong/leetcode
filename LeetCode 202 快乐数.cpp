#include <iostream>
#include <unordered_set>
using namespace std;

/*
* �ж�һ�����Ƿ���һ�����������������Ķ�����һ������������ÿһλ��ƽ���ͣ�������������1�����ǿ�������������Ǿ�һֱѭ����
* ������һ��������ǿ��ܻ�һֱѭ����ȥ��
* ������ǳ����˹�ϣ��һ�ڣ���ʼ��ʱ����ʵ���벻ͨ����������ϣ����ʲô��ϵ�������Ű�����ÿһλӳ�䵽��ϣ���ÿһ��λ�á�
* ���˴𰸲�֪�������������ڹ�ϣ���г��ֹ�����ô��˵����������ѭ�����Ͳ����ǿ����������û�г�����ѭ���ڣ��Ҳ���1���Ͱ������뵽��ϣ��
*/

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> uset;
		int sum = n;
		while (1) {
			sum = getsum(sum);
			if (sum == 1) return true;
			if (uset.find(sum) != uset.end())
				return false;
			else {
				uset.insert(sum);
			}
		}
	}

	//�ڶ�����
	bool isHappy1(int n) {
		unordered_set<int> uset;
		long long sum = 0;
		while (n != 1) {
			while (n) {  //���forѭ��������n�ĸ�λ��ƽ����
				sum += pow(n % 10, 2);
				n /= 10;
			}
			if (uset.find(sum) != uset.end())
				return false;
			else {
				uset.insert(sum);
				n = sum;
				sum = 0;
			}
		}
		return true;
	}
private:
	int getsum(int n) {
		int sum = 0;
		while (n) {
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
};

int main() {
	Solution st;
	cout << boolalpha << st.isHappy(19) << endl;
	cout << st.isHappy(2) << noboolalpha << endl;
	cout << boolalpha << st.isHappy1(19) << endl;
	cout << st.isHappy1(2) << noboolalpha << endl;
	return 0;
}