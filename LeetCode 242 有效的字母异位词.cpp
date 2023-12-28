#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		unordered_map<char, int> ump;
		for (auto& c : t) ump[c]++;
		for (auto& c : s) {
			auto cr = ump.find(c);
			if (cr == ump.end())
				return false;
			else {
				if (--cr->second == 0)
					ump.erase(c);
			}
		}
		if (ump.empty()) return true;
		else return false;
	}
};

int main() {
	Solution st;
	string s("anagram"), t("nagaram");
	bool flag = st.isAnagram(s, t);
	cout << boolalpha << flag << noboolalpha << endl;
	return 0;
}