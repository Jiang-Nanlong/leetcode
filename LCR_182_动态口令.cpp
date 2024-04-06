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

//上边的代码是我自己写的，也可以，下边的是看的别人的，我忘了C++的string重载了加法了

void main() {
	Solution st;
	string password("vbzkgsaoiu");
	int target = 2;
	cout << st.dynamicPassword(password, target) << endl;
}
