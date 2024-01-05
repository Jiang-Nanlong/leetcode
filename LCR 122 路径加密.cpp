#include <iostream>
#include <string>
using namespace std;

//��path�е�.�滻�ɿո�
class Solution {
public:
	string pathEncryption(string path) {
		string s = path;
		for (auto& c : s)
			if (c == '.')
				c = ' ';
		return s;
	}

	//����������չһ�£�����һ���ַ���s����s�еĿո��滻��%20
	//�����ڿռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(n)����ɣ������Ȱ��ַ����Ĵ�С�ĳɺ��ʵĴ�С��Ȼ��ʹ��˫ָ�룬�Ӻ���ǰ��һ��ָ��ָ����ַ�����ĩβ��һ��ָ�����ַ�����ĩβ��
	//Ϊʲô�ǴӺ���ǰ�أ������ǰ����Ļ�����Ҫ�ƶ���ߵ�һ���ַ���������ʱ�临�Ӷ���O(n^2)������ǴӺ���ǰ����O(n)
	string replaceSpace(string s) {
		//��ͳ���ַ���s�пո�ĸ���
		int countSpace = 0;
		for (char c : s)
			if (c == ' ')
				countSpace++;

		int oldSize = s.size();
		int newSize = s.size() + 2 * countSpace;
		s.resize(newSize);
		for (int i = oldSize - 1, j = newSize - 1; i < j; i--, j--) {
			if (s[i] != ' ')
				s[j] = s[i];
			else {
				s[j] = '0';
				s[j - 1] = '2';
				s[j - 2] = '%';
				j -= 2; //��Ϊforѭ���ڻ���һ��j--�������������-=2
			}
		}
		return s;
	}
};

int main() {
	Solution st;
	string path("a.aef.qerf.bb");
	string res = st.pathEncryption(path);
	cout << res << endl;

	res = st.replaceSpace(res);
	cout << res << endl;
	return 0;
}