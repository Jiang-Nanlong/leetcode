#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* 这个题是要判断ransomNote能不能用magazine中的字符表示出来，而且magazine中的每个字符只能用一次
* 这个题比较简单，开始用的是unordered_map发现结果不是很快，然后换成数组就特别快了。
*/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.size() > magazine.size()) return false;
		/*
		unordered_map<char,int> ump;
		for(auto &c:magazine) ump[c]++;
		for(auto &c:ransomNote)
			if(--ump[c]<0)
				return false;
		return true;
		*/
		int count[26] = { 0 };
		for (auto& c : magazine) count[c - 'a']++;
		for (auto& c : ransomNote)
			if (--count[c - 'a'] < 0)
				return false;
		return true;
	}
};

int main() {
	Solution st;
	string ransomNote("aa"), magazine("aab");
	cout << boolalpha << st.canConstruct(ransomNote, magazine) << noboolalpha << endl;
	return 0;
}