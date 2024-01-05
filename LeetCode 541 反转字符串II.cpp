#include <iostream>
#include <string>
using namespace std;

//����⿪ʼû�����ף������������۲�֪��զ���£�������Ҫд��ʱ���ַ��ֲ�̫��д�����Ȼ�Ǹ����⡣
//��Ŀ��Ҫ���Ǹ���һ���ַ���s����һ��k��ÿ���Ϊ2k���ַ�����תǰk������󵽴��ַ������һ��ʱ�����ʣ����ַ�����k���ͷ�תǰk��������k���Ļ�����ȫ����ת��
//��ʼ��������һ��flag����ʾ�ǲ��Ƿ�ת��true��ת��false����ת����������д��������ֱ�ӿ����ˣ��� ����


class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)) {
			if (i + k <= s.size()) {
				reverseHelper(s, i, i + k - 1);
				continue;
			}
			reverseHelper(s, i, s.size() - 1);
		}
		return s;
	}
	void reverseHelper(string& s, int begin, int end) {
		int left = begin, right = end;
		while (left <= right) {
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
};

int main() {
	Solution st;
	string s("abcdefg");
	int k = 2;
	string res = st.reverseStr(s, k);
	cout << res << endl;
	return 0;
}
