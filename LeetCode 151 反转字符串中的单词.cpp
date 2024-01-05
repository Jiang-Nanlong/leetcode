#include <iostream>
#include <string>
using namespace std;

//�������Ҫ��ת�����ﵥ�ʳ��ֵ�˳�򣬵��ǲ���תÿһ������
//��ʼ��ʱ�����������ȥ�������ж���Ŀո�Ȼ����������ȼ��������������Ӧ���ж��ٸ��ַ���Ȼ�����resize����string�Ĵ�С��Ȼ��������ָ�룬һ��ָ��֮ǰ���ַ�����һ��ָ������ӵģ�Ȼ��һ������һ�����ʵ�����߼ӣ�������substr
//���Ǻ������ֲ�̫��
class Solution {
public:
	string reverseWords(string s) {
		removeSpace(s);
		reverseHelper(s, 0, s.size() - 1);
		int start = 0;
		for (int i = 0; i <= s.size(); i++) {
			if (i == s.size() || s[i] == ' ') {
				reverseHelper(s, start, i - 1);
				start = i + 1;
			}
		}
		return s;
	}

private:
	void removeSpace(string& s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') {
				if (count != 0) s[count++] = ' ';  //����õ��ʲ��ǵ�һ�����ʾ�������ǰ�߲���һ���ո�

				while (i < s.size() && s[i] != ' ') {
					s[count++] = s[i++];
				}
			}
		}
		s.resize(count);
	}

	void reverseHelper(string& s, int begin, int end) {
		while (begin <= end) {
			swap(s[begin++], s[end--]);
		}
	}
};

//���ǿ��˴�������¼�Ĵ��룬���������裺1.��ȥ������Ŀո�  2��Ȼ��ת��������  3.Ȼ����������еĵ��ʣ��ٰ�ÿ�����ʷ�ת������
//��һ��ȥ������Ŀո��õ���LeetCode27�����˫ָ�뷽��
//��������õ���LeetCode 344��ķ�ת�ַ����ķ���
//����⻹�ǱȽ��ۺϵ�

int main() {
	Solution st;
	string s("the sky is blue");
	string res = st.reverseWords(s);
	cout << res << endl;
	return 0;
}