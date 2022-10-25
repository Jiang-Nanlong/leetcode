#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int numberOfWords = words.size(), lengthOfWord = words[0].size(), stringLen = s.size();
		vector<int> res;
		if (stringLen < numberOfWords * lengthOfWord) return res;

		unordered_map<string, int> hashmap;
		for (string s : words) {
			hashmap[s] ++;
		}
		
		unordered_map<string, int> mp;
		for (int i = 0; i < stringLen; i++) {
			string subs = s.substr(i, lengthOfWord);
			mp[subs] ++;
			if (mp == hashmap) res.push_back(i - numberOfWords * lengthOfWord);
		}

		return res;
	}
};