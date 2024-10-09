#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
	//public:
	//	string minWindow(string s, string t) {
	//		int i = 0, j = 0, k = 0, count = INT_MAX;
	//		unordered_map<char, int> tump, sump;
	//		for (auto& c : t) tump[c]++;
	//		for (; j < s.size(); j++) {
	//			sump[s[j]]++;
	//			while (compareUnorderedmap(sump, tump, t)) {
	//				sump[s[i]]--;
	//				if (sump[s[i]] == 0) {
	//					sump.erase(s[i]);
	//				}
	//				/*k = i;
	//				count = min(count, j - i + 1);*/
	//				if ((j - i + 1) <= count) {
	//					k = i;
	//					count = (j - i + 1);
	//				}
	//				i++;
	//			}
	//		}
	//		return count == INT_MAX ? "" : s.substr(k, count);
	//	}
	//private:
	//	bool compareUnorderedmap(unordered_map<char, int>& a, unordered_map<char, int>& b, string& t) {
	//		if (a.size() >= b.size()) {
	//			for (auto& c : t) {
	//				if (a[c] < b[c]) return false;
	//			}
	//			return true;
	//		}
	//		else return false;
	//	}
	//上边是我自己写的，模仿着之前的滑动窗口的题，写了一个专门的比较函数来比较，但是如果当s和t都特别大的时候就运行超时了。
	//后边看了代码随想录的代码才写出来的，但是还是弄不太清
public:
	string minWindow(string s, string t) {
		int i = 0, j = 0, cnt = 0, k = 0, count = INT_MAX;
		unordered_map<char, int> sump, tump;
		for (auto& c : t) tump[c]++;
		for (; j < s.size(); j++) {
			sump[s[j]]++;
			if (sump[s[j]] <= tump[s[j]]) cnt++;
			while (sump[s[i]] > tump[s[i]]) sump[s[i++]]--;
			if (cnt == t.size() && (j - i + 1) <= count) {
				k = i;
				count = (j - i + 1);
			}
		}
		return count == INT_MAX ? "" : s.substr(k, count);
	}


	// 后来在滑动窗口专项练习中又刷到这个题了，这个题的一个难点就是何时缩小窗口，
	// 如果按着笨方法的话，要一个个的看t中的各个元素的数量在当前窗口内是否都满足了，如果满足的话就可以缩小窗口了。
	// 但是这种方法不用想都会超时。
	// 引入了一个cnt的变量，这个变量只用来统计“必要字符的数量”，也就是说如果窗口内当前元素的数量小于t中该元素的数量，
	// 说明当前这个元素是组成t中元素的一个必要元素，就把cnt++，如果窗口内的当前字符的数目已经超过了t中该字符的数量，那说明当前字符不是一个必要的字符。
	// 当cnt和t.size()相同时，说明我们已经凑够了t中的每个字符，现在就可以缩小窗口了。如果缩小了窗口后，当前窗口的内的该字符的数量少于了t中该字符的数量，
	// 那说明当前字符是一个必要的字符，所以cnt就得减一，此时也就只能再扩大窗口了。
	string minWindow1(string s, string t) {
		unordered_map<char, int> umap, umap2;
		for (char c : t)
			umap[c]++;

		int start = 0, minlen = INT_MAX;
		int cnt = 0;
		for (int i = 0, j = 0; j < s.size(); j++) {
			char c = s[j];
			if (umap.find(c) != umap.end()) {
				if (++umap2[c] <= umap[c])
					cnt++;
			}
			while (cnt == t.size()) {
				c = s[i];
				if (umap.find(c) != umap.end()) {
					if (--umap2[c] < umap[c])
						cnt--;
				}
				if (j - i + 1 < minlen) {
					start = i;
					minlen = j - i + 1;
				}
				i++;
			}
		}
		return minlen == INT_MAX ? "" : s.substr(start, minlen);
	}

	string minWindow2(string s, string t) {
		int count[128], window[128];
		memset(count, 0, sizeof(count));
		memset(window, 0, sizeof(window));

		for (char c : t)
			count[c]++;

		int start = 0, minlen = INT_MAX;
		int cnt = 0;
		for (int i = 0, j = 0; j < s.size(); j++) {
			char c = s[j];
			++window[c];
			if (count[c] >= window[c])
				cnt++;

			while (cnt == t.size()) {
				c = s[i];
				--window[c];
				if (window[c] < count[c])
					cnt--;
				if (j - i + 1 < minlen) {
					start = i;
					minlen = j - i + 1;
				}
				i++;
			}
		}
		return minlen == INT_MAX ? "" : s.substr(start, minlen);
	}

};

//感觉这个代码在判断缩小窗口和确定每个窗口内是不是包含了t中所有的字符，这两个地方都写的特别巧
//又看了几个别人写的代码，对滑动窗口有了一点理解了，思路都是双指针，但是缩小窗口的条件和判断每个窗口是否符合要求要因题而异

int main() {
	Solution st;
	string s("cabwefgewcwaefgcf"), t("cae");
	string res = st.minWindow(s, t);
	for (auto& c : res)
		cout << c << "  ";
	cout << endl;

	string res1 = st.minWindow1(s, t);
	for (auto& c : res1)
		cout << c << "  ";
	cout << endl;

	string res2 = st.minWindow2(s, t);
	for (auto& c : res2)
		cout << c << "  ";
	cout << endl;
	return 0;
}