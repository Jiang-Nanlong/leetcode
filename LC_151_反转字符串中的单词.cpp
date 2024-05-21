#include <iostream>
#include <string>
using namespace std;


#include <iostream>
#include <string>
using namespace std;

//这个题是要反转句子里单词出现的顺序，但是不翻转每一个单词
//开始的时候我想的是先去掉句子中多余的空格，然后后来又想先计算出正常句子中应该有多少个字符，然后调用resize调整string的大小，然后用两个指针，一个指向之前的字符串，一个指向新添加的，然后一个单词一个单词的往里边加，最后调用substr
//但是后来发现不太行
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
			if (s[i] != ' ') {  //能从这进来说明s[i]的前一个是空格
				if (count != 0) s[count++] = ' ';  //如果该单词不是第一个单词就在它的前边补上一个空格

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


	//第二次做
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
	//第三次做，这个题的主要难点还是移除多余的空格
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

	void removeSpace2(string& s) {  // 移除多余的0
		int slow = 0, fast = 0;
		while (fast < s.size()) {
			if ((s[fast] != ' ') || (fast > 0 && s[fast] == ' ' && s[fast - 1] != ' ')) // 如果当前fast为空格，而fast-1为字母时，说明这个空格该存在。但是这会导致最后一个可能是空格，所以最后要判断s[slow-1]是否是空格
				s[slow++] = s[fast++];
			else
				fast++;  //前导空格会直接走这里，往后移动fast指针
		}
		if (s[slow - 1] == ' ') s.resize(slow - 1);
		else s.resize(slow);
	}

public:
	// 第四次做了
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

//这是看了代码随想录的代码，分三个步骤：1.先去掉多余的空格  2。然后反转整个句子  3.然后遍历句子中的单词，再把每个单词反转回来。
//第一步去除多余的空格，用到了LeetCode27题里的双指针方法
//后边两步用到了LeetCode 344里的翻转字符串的方法
//这个题还是比较综合的

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