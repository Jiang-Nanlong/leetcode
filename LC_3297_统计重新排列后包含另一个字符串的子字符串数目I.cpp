#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// 给定两个字符串word1和word2，对于word1中的某个子字符串，如果word2重新排序后是该字符串的前缀，那么说该子字符串是一个合法字符窜。
// 返回合法字符串的数目

// 和LeetCode 3298一模一样，只不过数据量比较小
class Solution {
public:
	long long validSubstringCount(string word1, string word2) {
		if (word1.size() < word2.size()) return 0;

		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		long long res = 0;
		int cnt = 0, n = word1.size();  // 还是和76题一样，用cnt来记录必要字符的数目
		int window[26];
		memset(window, 0, sizeof(window));
		for (int i = 0, j = 0; j < n; j++) {
			int index = word1[j] - 'a';
			if (++window[index] <= count[index])
				++cnt;
			while (cnt == word2.size()) {
				res += n - j; // 如果当前以i开头，j结尾的字符串是合法的，那么以j后边所有字符结尾的字符串也都是合法的
				index = word1[i] - 'a';
				if (--window[index] < count[index])
					cnt--;
				i++;
			}
		}
		return res;
	}

	// 一样的做法，上边统计的是以i为左端点，以不同右端点为结尾的子字符串的数目
	// 下边统计的是以j为右端点，以不同左端点开始的子字符串的数目
	long long validSubstringCount1(string word1, string word2) {
		if (word1.size() < word2.size())
			return 0;
		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		long long res = 0;
		int cnt = 0, n = word1.size();
		int window[26];
		memset(window, 0, sizeof(window));
		for (int i = 0, j = 0; j < n; j++) {
			int index = word1[j] - 'a';
			if (++window[index] <= count[index])
				++cnt;
			while (cnt == word2.size()) {
				index = word1[i] - 'a';
				if (--window[index] < count[index])
					cnt--;
				i++;
			}
			res += i;
		}
		return res;
	}

    // 之后有一次做，想起来这是越长越合理的滑动窗口题，但是这里只能想到一个个比较窗口数组和模式串数组
	long long validSubstringCount2(string word1, string word2) {
		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		int temp[26];
		memset(temp, 0, sizeof(temp));
		auto check = [&]() -> bool {
			for (int i = 0; i < 26; i++)
				if (temp[i] < count[i])
					return false;

			return true;
		};

		int n = word1.size();
		long long res = 0;

		for (int i = 0, j = 0; i <= j && j < n; j++) {
			temp[word1[j] - 'a']++;

			while (check()) {
				res += n - j;
				temp[word1[i++] - 'a']--;
			}
		}
		return res;
	}

        // 看了看之前写的代码，感觉有点巧妙，直接用一个变量cnt来统计必要的字符的个数，一旦必要字符的个数和word2的长度相同了，说明窗口内的元素已经可以凑出完整的word2
	long long validSubstringCount3(string word1, string word2) {
		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		int temp[26];
		memset(temp, 0, sizeof(temp));

		int cnt = 0;
		int n = word1.size();
		long long res = 0;

		for (int i = 0, j = 0; i <= j && j < n; j++) {
			if (++temp[word1[j] - 'a'] <= count[word1[j] - 'a'])
				++cnt;

			while (cnt == word2.size()) {
				res += n - j;
				if (--temp[word1[i] - 'a'] < count[word1[i] - 'a'])
					--cnt;
				i++;
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	string word1("abcabc"), word2("abc");
	cout << st.validSubstringCount(word1, word2) << endl;
	cout << st.validSubstringCount1(word1, word2) << endl;
	return 0;
}