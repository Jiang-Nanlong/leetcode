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
	return 0;
}