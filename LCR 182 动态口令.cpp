#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string dynamicPassword(string password, int target) {
		/*
		int oldSize = password.size();
		password.resize(oldSize+target);
		for(int i = 0;i<target;i++)
			password[oldSize++] = password[i];
		return password.substr(target);
		*/
		string s1 = password.substr(0, target);
		string s2 = password.substr(target);
		return s2 + s1;
	}
};

//�ϱߵĴ��������Լ�д�ģ�Ҳ���ԣ��±ߵ��ǿ��ı��˵ģ�������C++��string�����˼ӷ���

void main() {
	Solution st;
	string password("vbzkgsaoiu");
	int target = 2;
	cout << st.dynamicPassword(password, target) << endl;
}