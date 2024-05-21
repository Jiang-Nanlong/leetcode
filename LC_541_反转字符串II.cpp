#include <iostream>
#include <string>
#include <algorithm>
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

	//这是第二次写的代码，这个题的难点就是在于最后翻转不够2k个的时候，这时又分为两种，一种是不到k个，一种是大于k小于2k个字符。
	string reverseStr1(string s, int k) {
		int count = s.size() / k;
		int i = 0;
		while (i < count) {  //这里可以解决第二种情况，大于k小于2k，可以翻转前k个。
			swapHelper(s, i * k, i * k + k - 1);
			i += 2;
		}

		swapHelper(s, i * k, s.size() - 1);  //这两种情况都会运行这一步，如果是第一种情况的话，就很好理解。主要是第二种情况的后半部分，也会运行这里，比如说abcdefghi，k=3这种，运行到这时，i=4，这时已经超过数组界限了，
		//即使进入了swapHelper函数，也不会进入while循环。但是如果是第一种情况，这剩余不到k个字符，本该就在i*k的位置
		return s;
	}

	//第三次做，其实可以直接使用C++自带的reverse函数
	string reverseStr2(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			if (i + k <= s.size()) {
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			reverse(s.begin() + i, s.end());
		}
		return s;
	}

	// 第四次做了
	string reverseStr3(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			if (i + k <= s.size()) {
				std::reverse(s.begin() + i, s.begin() + i + k);
			}
			else {
				std::reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}

private:
	void swapHelper(string& s, int begin, int end) {
		int left = begin, right = end;
		while (left <= right) {
			swap(s[left++], s[right--]);
		}
	}

};

int main() {
	Solution st;
	string s("abcdefg");
	int k = 2;
	string res = st.reverseStr(s, k);
	cout << res << endl;
	string res1 = st.reverseStr1(s, k);
	cout << res1 << endl;
	string res2 = st.reverseStr2(s, k);
	cout << res2 << endl;
	string res3 = st.reverseStr3(s, k);
	cout << res3 << endl;
	return 0;
}
