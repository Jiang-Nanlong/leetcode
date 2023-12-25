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
		//return slow;   //���Բ�����slow������ʹ��resize��������string����slow��С�������Ͳ��ÿ��ⷵ��slow��Ȼ��Ƚ���
		s.resize(slow);
	}
};
//�����ķ������ǱȽ������뵽�ģ��ÿ���ָ�룬�����ָ��������#���Ͱ���ָ���˸�һ��

int main() {
	Solution st;
	string s("ab#c"), t("ad#c");
	bool flag = st.backspaceCompare(s, t);
	cout << flag << endl;
	return 0;
}