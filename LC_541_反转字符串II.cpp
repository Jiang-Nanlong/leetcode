#include <iostream>
#include <string>
#include <algorithm>
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

	//���ǵڶ���д�Ĵ��룬�������ѵ�����������ת����2k����ʱ����ʱ�ַ�Ϊ���֣�һ���ǲ���k����һ���Ǵ���kС��2k���ַ���
	string reverseStr1(string s, int k) {
		int count = s.size() / k;
		int i = 0;
		while (i < count) {  //������Խ���ڶ������������kС��2k�����Է�תǰk����
			swapHelper(s, i * k, i * k + k - 1);
			i += 2;
		}

		swapHelper(s, i * k, s.size() - 1);  //�������������������һ��������ǵ�һ������Ļ����ͺܺ���⡣��Ҫ�ǵڶ�������ĺ�벿�֣�Ҳ�������������˵abcdefghi��k=3���֣����е���ʱ��i=4����ʱ�Ѿ�������������ˣ�
		//��ʹ������swapHelper������Ҳ�������whileѭ������������ǵ�һ���������ʣ�಻��k���ַ������þ���i*k��λ��
		return s;
	}

	//������������ʵ����ֱ��ʹ��C++�Դ���reverse����
	string reverseStr2(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			if (i + k <= s.size()) {
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			reverse(s.begin() + i, s.end());
		}
		return s;
	}

	// ���Ĵ�����
	string reverseStr3(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			if (i + k <= s.size()) {
				std::reverse(s.begin() + i, s.begin() + i + k);
			}
			else {
				std::reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}

private:
	void swapHelper(string& s, int begin, int end) {
		int left = begin, right = end;
		while (left <= right) {
			swap(s[left++], s[right--]);
		}
	}

};

int main() {
	Solution st;
	string s("abcdefg");
	int k = 2;
	string res = st.reverseStr(s, k);
	cout << res << endl;
	string res1 = st.reverseStr1(s, k);
	cout << res1 << endl;
	string res2 = st.reverseStr2(s, k);
	cout << res2 << endl;
	string res3 = st.reverseStr3(s, k);
	cout << res3 << endl;
	return 0;
}
