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

public:
	//�ڶ���������û������������������һ��Ҳû������
	//���˴��Ժ�������������һ���ַ��������ظ��Ӵ����ɵģ���ô��һ��������ͬ������ǰ��׺������ǰ׺�ͺ�׺��λ�ù�ϵ�����Թ۲쵽���ǲ��ص���λ�þ�Ӧ����Ҫ������ַ�����
	bool repeatedSubstringPattern1(string s) {
		string t = s + s;
		t.erase(t.begin());
		t.erase(t.end() - 1);
		if (t.find(s) != -1)
			return true;
		return false;
	}

	bool repeatedSubstringPattern2(string s) {
		int* next = new int[s.size()];
		getNext1(next, s);
		if (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0)return true;
		return false;
	}
	void getNext1(int* next, string s) {
		int j = 0;
		next[0] = j;
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j])
				j = next[j - 1];
			if (s[i] == s[j])
				j++;
			next[i] = j;
		}
	}


};

void main() {
	Solution st;
	string s1("abab"), s2("aba");
	cout << boolalpha << st.repeatedSubstringPattern(s1) << endl;
	cout << st.repeatedSubstringPattern(s2) << noboolalpha << endl;
	cout << boolalpha << st.repeatedSubstringPattern2(s1) << endl;
	cout << st.repeatedSubstringPattern2(s2) << noboolalpha << endl;
}