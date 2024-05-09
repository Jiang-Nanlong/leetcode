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
			if (s[i] != ' ') {
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
};

//这是看了代码随想录的代码，分三个步骤：1.先去掉多余的空格  2。然后反转整个句子  3.然后遍历句子中的单词，再把每个单词反转回来。
//第一步去除多余的空格，用到了LeetCode27题里的双指针方法
//后边两步用到了LeetCode 344里的翻转字符串的方法
//这个题还是比较综合的

int main() {
	Solution st;
	string s("the sky is blue");
	string res = st.reverseWords(s);
	cout << res << endl;
	return 0;
}
