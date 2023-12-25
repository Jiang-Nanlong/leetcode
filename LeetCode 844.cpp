#include <iostream>
#include <string>
using namespace std;

class Solution {
	//public:
	//	bool backspaceCompare(string s, string t) {
	//		cout << compareHelper(s) << endl;
	//
	//		cout << compareHelper(t) << endl;
	//		if (s == t)return true;
	//		else return false;
	//	}
	//private:
	//	int compareHelper(string& s) {
	//		int slow = 0, fast = 0;
	//		for (; fast < s.size(); fast++) {
	//			if (s[fast] != '#') {
	//				s[slow++] = s[fast];
	//			}
	//			else {
	//				slow = slow - 1 > 0 ? slow - 1 : 0;
	//			}
	//		}
	//		return slow;
	//	}
public:
	bool backspaceCompare(string s, string t) {
		compareHelper(s);
		compareHelper(t);
		return (s == t);
	}
private:
	void compareHelper(string& s) {
		int slow = 0, fast = 0;
		for (; fast < s.size(); fast++) {
			if (s[fast] != '#') {
				s[slow++] = s[fast];
			}
			else {
				slow = slow - 1 > 0 ? slow - 1 : 0;
			}
		}
		//return slow;   //可以不返回slow，而是使用resize函数，把string换成slow大小，这样就不用刻意返回slow，然后比较了
		s.resize(slow);
	}
};
//这个题的方法还是比较容易想到的，用快慢指针，如果快指针遇到了#，就把慢指针退格一个

int main() {
	Solution st;
	string s("ab#c"), t("ad#c");
	bool flag = st.backspaceCompare(s, t);
	cout << flag << endl;
	return 0;
}