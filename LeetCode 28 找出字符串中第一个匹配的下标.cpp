#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int n = haystack.size(), m = needle.size();
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
		return -1;
	}
};

void main() {
	Solution st;
	string haystack("sadbutsad"), needle("sad");
	cout << st.strStr(haystack, needle) << endl;
}