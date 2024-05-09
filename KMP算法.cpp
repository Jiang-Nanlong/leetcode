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
			while (j > 0 && haystack[i] != needle[j]) {  //其实这个地方我还有点不明白，next数组不是已经构造好了吗，这里只需要回跳到j的上一个位置就行了，回退一下不就行了吗，为什么还要用while
				//好吧，手动演示过一遍就又懂了
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

	//第二次做，求next数组的时候有三个环节，一是j、i、next数组的初始化问题；二是在构造的过程中遇到前后缀不相同的情况；三是构造过程中遇到前后缀相同的情况
	//第一个问题：这里的next数组是跟手写的一样，next[i]记录第i个位置前后缀的最长长度。i和j表示后缀序列的末尾和前缀序列的末尾。而前缀又是不包含最后一个字符的所有以第一个字符开头的连续子串，后缀是不包含第一个字符的所有以最后一个字符结尾的连续子串
	//所以这里的j是从0开始，i是从1开始，分别指向只有两个字符时的前缀末尾和后缀末尾。
	//第二个问题：在构造的过程中遇到不匹配的情况，这里就跟在使用next数组进行匹配时一样，如果遇到不匹配的，就把j按着next数组回退，回退到s[i]==s[j]的时候，然后更新next数组
	//第三个问题：相等的时候就i和j都往后移，然后更新next[i]
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