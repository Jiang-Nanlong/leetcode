#include <iostream>
#include <string>
using namespace std;

//把path中的.替换成空格
class Solution {
public:
	string pathEncryption(string path) {
		string s = path;
		for (auto& c : s)
			if (c == '.')
				c = ' ';
		return s;
	}

	//这个题可以扩展一下，给定一个字符串s，把s中的空格替换成%20
	//可以在空间复杂度O(1)，时间复杂度O(n)内完成，就是先把字符串的大小改成合适的大小，然后使用双指针，从后往前，一个指针指向旧字符串的末尾，一个指向新字符串的末尾。
	//为什么是从后往前呢，如果从前往后的话，需要移动后边的一大串字符，这样的时间复杂度是O(n^2)，如果是从后往前就是O(n)
	string replaceSpace(string s) {
		//先统计字符串s中空格的个数
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
				j -= 2; //因为for循环内还有一个j--，所以这里就先-=2
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