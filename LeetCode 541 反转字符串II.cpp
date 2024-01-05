#include <iostream>
#include <string>
using namespace std;

//这个题开始没读明白，后来看了讨论才知道咋回事，但是真要写的时候，又发现不太好写，这居然是个简单题。
//题目的要求是给定一个字符串s，和一个k，每组分为2k个字符，反转前k个，最后到达字符串最后一组时，如果剩余的字符大于k个就反转前k个，不够k个的话，就全部反转。
//开始我是想用一个flag来表示是不是反转，true反转，false不翻转，后来发现写不出，就直接看答案了，唉 愁死


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
