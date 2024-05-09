#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int KMP(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;
		int* next = new int[needle.size()];
		getNext(next, needle);
		int j = 0;
		for (int i = 0; i < haystack.size(); i++) {
			while (j > 0 && haystack[i] != needle[j])
				j = next[j - 1];
			if (haystack[i] == needle[j])
				j++;
			if (j == needle.size())
				return i - j + 1;
		}
		return -1;
	}

	int KMP1(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;
		int* next = new int[needle.size()];
		getNext1(next, needle);
		for (int i = 0, j = 0; i < haystack.size(); i++) {
			while (j > 0 && haystack[i] != needle[j]) {  //��ʵ����ط��һ��е㲻���ף�next���鲻���Ѿ��������������ֻ��Ҫ������j����һ��λ�þ����ˣ�����һ�²���������Ϊʲô��Ҫ��while
				//�ðɣ��ֶ���ʾ��һ����ֶ���
				j = next[j - 1];
			}
			if (haystack[i] == needle[j])
				j++;
			if (j == needle.size())
				return i - j + 1;
		}
		return -1;
	}
private:
	void getNext(int* next, string s) {
		int j = 0;
		next[0] = 0;
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j])
				j = next[j - 1];
			if (s[i] == s[j])
				j++;
			next[i] = j;
		}
	}

	//�ڶ���������next�����ʱ�����������ڣ�һ��j��i��next����ĳ�ʼ�����⣻�����ڹ���Ĺ���������ǰ��׺����ͬ����������ǹ������������ǰ��׺��ͬ�����
	//��һ�����⣺�����next�����Ǹ���д��һ����next[i]��¼��i��λ��ǰ��׺������ȡ�i��j��ʾ��׺���е�ĩβ��ǰ׺���е�ĩβ����ǰ׺���ǲ��������һ���ַ��������Ե�һ���ַ���ͷ�������Ӵ�����׺�ǲ�������һ���ַ������������һ���ַ���β�������Ӵ�
	//���������j�Ǵ�0��ʼ��i�Ǵ�1��ʼ���ֱ�ָ��ֻ�������ַ�ʱ��ǰ׺ĩβ�ͺ�׺ĩβ��
	//�ڶ������⣺�ڹ���Ĺ�����������ƥ������������͸���ʹ��next�������ƥ��ʱһ�������������ƥ��ģ��Ͱ�j����next������ˣ����˵�s[i]==s[j]��ʱ��Ȼ�����next����
	//���������⣺��ȵ�ʱ���i��j�������ƣ�Ȼ�����next[i]
	void getNext1(int* Next, string s) {
		int j = 0;
		Next[0] = j;
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j]) {
				j = Next[j - 1];
			}
			if (s[i] == s[j])
				j++;
			Next[i] = j;
		}
	}
};

void main() {
	Solution st;
	string haystack("aabaabaafa"), needle("aabaaf");
	cout << st.KMP(haystack, needle) << endl;
}