#include <iostream>
#include <string>
using namespace std;

//������Ȼ��һ�����⣬��Ҳ̫����

class Solution {
public:
	/*bool repeatedSubstringPattern(string s) {  //�ƶ�ƥ�� ʱ�临�Ӷ�O(n)
		string t = s + s;
		t.erase(t.begin());
		t.erase(t.end() - 1);
		if (t.find(s) != -1) return true;
		return false;

	}*/

	//KMP����  ʱ�临�Ӷ�O(n)
	bool repeatedSubstringPattern(string s) {
		if (s.size() == 0) return false;
		int* next = new int[s.size()];
		getNext(s, next);
		if ((next[s.size() - 1] != 0) && (s.size() % (s.size() - next[s.size() - 1]) == 0))   //����������С�ظ��Ӵ�����ǰs.size() - next[s.size() - 1]��Ԫ�ء�  
			//next[s.size() - 1] != 0��Ϊ�˷�ֹ����abac���������������������û������������ж�Ϊ���ظ��Ӵ�����ʵ��û�еġ�
			return true;
		return false;
	}
private:
	void getNext(const string& s, int* next) {
		int i = 0;
		next[0] = 0;
		for (int j = 1; j < s.size(); j++) {
			while (i > 0 && s[i] != s[j])
				i = next[i - 1];
			if (s[i] == s[j])
				i++;
			next[j] = i;
		}
	}
};

void main() {
	Solution st;
	string s1("abab"), s2("aba");
	cout << boolalpha << st.repeatedSubstringPattern(s1) << endl;
	cout << st.repeatedSubstringPattern(s2) << noboolalpha << endl;
}