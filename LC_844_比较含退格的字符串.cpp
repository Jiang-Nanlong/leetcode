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

	//�ڶ������Ĵ���>>  ����һ�ε��߼�һ����ֻ�����ظ�����ûд�ɺ���
	bool backspaceCompare1(string s, string t) {
		int i = 0, j = 0;
		for (; i < s.size(); i++) {
			if (s[i] != '#') {
				s[j] = s[i];
				j++;
			}
			else {
				j = j - 1 > 0 ? j - 1 : 0;  //��ʼ����ط�ûд�ԣ�û�뵽�кü��������˸�ʹ����ָ��С��0�����
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
	//�ڶ������Ĵ���<<


	//��������
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
	cout << boolalpha << st.backspaceCompare1(s, t) << noboolalpha << endl;
	cout << boolalpha << st.backspaceCompare2(s, t) << noboolalpha << endl;
	return 0;
}