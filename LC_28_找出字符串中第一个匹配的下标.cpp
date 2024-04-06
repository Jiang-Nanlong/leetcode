#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		/*int n = haystack.size(), m = needle.size();   //暴力做法 时间复杂度是O(m*n)
		for (int i = 0; i < n - m + 1; i++) {
			bool flag = true;
			for (int j = 0; j < m; j++) {
				if (haystack[i + j] != needle[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				return i;
		}
		return -1;*/


		//KMP做法  时间复杂度是O(m+n)
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
};

void main() {
	Solution st;
	string haystack("sadbutsad"), needle("sad");
	cout << st.strStr(haystack, needle) << endl;
}
