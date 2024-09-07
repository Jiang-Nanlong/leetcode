#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

//给你一个字符串S，找出所有长度为K且不含重复字符的子串，请你返回全部满足要求的子串的数目

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k)
			return 0;

		unordered_map<char,int> umap;
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			++umap[s[i]];
			if (i >= k && --umap[s[i - k]] == 0)
				umap.erase(s[i - k]);
			if (umap.size() == k)
				res++;
		}
		return res;
	}
};

int main() {
	Solution st;
	string s("havefunonleetcode");
	int k = 5;
	cout << st.numKLenSubstrNoRepeats(s, k) << endl;
	return 0;
}