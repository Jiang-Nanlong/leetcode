#include <iostream>
#include <string>
using namespace std;


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
			if (s[i] != ' ') {  //�ܴ������˵��s[i]��ǰһ���ǿո�
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


	//�ڶ�����
public:
	string reverseWords1(string s) {
		removeSpace1(s);
		swapHelper(s, 0, s.size() - 1);
		for (int slow = 0, fast = 0; fast <= s.size(); fast++) {
			if (s[fast] == ' ' || fast == s.size()) {
				swapHelper(s, slow, fast - 1);
				slow = fast + 1;
			}
		}
		return s;
	}

private:
	void removeSpace1(string& s) {
		int slow = 0, fast = 0;
		for (; fast < s.size(); fast++) {
			if (s[fast] == ' ') {
				continue;
			}
			else {
				if (slow != 0 && s[fast - 1] == ' ')
					s[slow++] = ' ';
				s[slow++] = s[fast];
			}
		}
		s.resize(slow);
	}
	void swapHelper(string& s, int begin, int end) {
		int left = begin, right = end;
		while (left <= right)
			swap(s[left++], s[right--]);
	}

public:
	//������������������Ҫ�ѵ㻹���Ƴ�����Ŀո�
	string reverseWords2(string s) {
		removeSpace2(s);
		cout << s << endl;
		reverse(s.begin(), s.end());
		int left = 0, right = 0;
		while (right <= s.size()) {
			if (s[right] == ' ' || right == s.size()) {
				reverse(s.begin() + left, s.begin() + right);
				left = right + 1;
			}
			right++;
		}
		return s;
	}

	void removeSpace2(string& s) {  // �Ƴ������0
		int slow = 0, fast = 0;
		while (fast < s.size()) {
			if ((s[fast] != ' ') || (fast > 0 && s[fast] == ' ' && s[fast - 1] != ' ')) // �����ǰfastΪ�ո񣬶�fast-1Ϊ��ĸʱ��˵������ո�ô��ڡ�������ᵼ�����һ�������ǿո��������Ҫ�ж�s[slow-1]�Ƿ��ǿո�
				s[slow++] = s[fast++];
			else
				fast++;  //ǰ���ո��ֱ������������ƶ�fastָ��
		}
		if (s[slow - 1] == ' ') s.resize(slow - 1);
		else s.resize(slow);
	}

public:
	// ���Ĵ�����
	string reverseWords3(string s) {
		removeextraspace(s);
		cout << s << endl;
		reverse(s.begin(), s.end());
		for (int slow = 0, fast = 0; fast <= s.size(); fast++) {
			if (s[fast] == ' ' || fast == s.size()) {
				reverse(s.begin() + slow, s.begin() + fast);
				slow = fast + 1;
			}
		}
		return s;
	}

	void removeextraspace(string& s) {
		int slow = 0, fast = 0;
		while (fast < s.size()) {
			if (s[fast] == ' ') {
				if (slow == 0) {
					fast++;
					continue;
				}else if (fast > 0 && s[fast - 1] != ' ') {
					s[slow++] = s[fast];
				}
			}
			else
				s[slow++] = s[fast];
			fast++;
		}
		if (slow > 0 && s[slow - 1] == ' ')
			slow--;
		s.resize(slow);
	}
};

//���ǿ��˴�������¼�Ĵ��룬���������裺1.��ȥ������Ŀո�  2��Ȼ��ת��������  3.Ȼ����������еĵ��ʣ��ٰ�ÿ�����ʷ�ת������
//��һ��ȥ������Ŀո��õ���LeetCode27�����˫ָ�뷽��
//��������õ���LeetCode 344��ķ�ת�ַ����ķ���
//����⻹�ǱȽ��ۺϵ�

int main() {
	Solution st;
	string s("  the  sky is blue   ");
	string res = st.reverseWords(s);
	cout << res << endl;
	string res1 = st.reverseWords1(s);
	cout << res1 << endl;
	string res2 = st.reverseWords2(s);
	cout << res2 << endl;
	string res3 = st.reverseWords3(s);
	cout << res3 << endl;
	return 0;
}