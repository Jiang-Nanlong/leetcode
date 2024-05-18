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

	//第二次做的代码>>  跟第一次的逻辑一样，只不过重复部分没写成函数
	bool backspaceCompare1(string s, string t) {
		int i = 0, j = 0;
		for (; i < s.size(); i++) {
			if (s[i] != '#') {
				s[j] = s[i];
				j++;
			}
			else {
				j = j - 1 > 0 ? j - 1 : 0;  //开始这个地方没写对，没想到有好几个连续退格使得慢指针小于0的情况
			}
		}
		s.resize(j);

		i = 0, j = 0;
		for (; i < t.size(); i++) {
			if (t[i] != '#') {
				t[j] = t[i];
				j++;
			}
			else {
				j = j - 1 > 0 ? j - 1 : 0;
			}
		}
		t.resize(j);
		return s == t;
	}
	//第二次做的代码<<


	//第三次做
	bool backspaceCompare2(string s, string t) {
		Helper(s);
		Helper(t);
		return s == t;
	}

	void Helper(string& s) {
		int slow = 0, fast = 0;
		while (fast < s.size()) {
			if (s[fast] != '#') {
				s[slow] = s[fast];
				slow++;
			}
			else {
				slow--;
				if (slow < 0)
					slow = 0;
			}
			fast++;
		}
		s.resize(slow);
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
	cout << boolalpha << st.backspaceCompare1(s, t) << noboolalpha << endl;
	cout << boolalpha << st.backspaceCompare2(s, t) << noboolalpha << endl;
	return 0;
}