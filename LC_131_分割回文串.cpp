#include <iostream>
#include <string>
#include <vector>
using namespace std;

//给定一个字符串s，将s分割成一些子串，使得每个子串都是回文子串，返回s的所有分割方案。回文串就是正着读和反着读都是一样的字符串。
//开始的时候我想着用双指针判断一个子串是不是回文串，但是又担心是不是还有更巧妙的方法，后来一看才发现还真是这么弄。
//这个题可以转化成树形结构，所以才能用回溯。

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<string> cb;
		vector<vector<string>> res;
		Helper(s, 0, cb, res);
		return res;
	}
	void Helper(string& s, int startindex, vector<string>& cb, vector<vector<string>>& res) {
		if (startindex == s.size()) {
			res.push_back(cb);
			return;
		}

		for (int i = startindex; i < s.size(); i++) {
			if (isPalindrome(s, startindex, i)) {
				string temp = s.substr(startindex, i - startindex + 1);  //这一句是整段程序的关键
				cb.push_back(temp);
			}
			else {
				continue;
			}
			Helper(s, i + 1, cb, res);
			cb.pop_back();
		}
	}

	bool isPalindrome(string& s, int begin, int end) {
		for (int i = begin, j = end; i <= j; i++, j--) {
			if (s[i] != s[j]) return false;
		}
		return true;
	}


	//第二遍做，还是没想出怎么做
	vector<vector<string>> res;
	vector<string> path;

	vector<vector<string>> partition1(string s) {
		backtracking(s, 0);
		return res;
	}

	void backtracking(string& s, int startIndex) {
		if (startIndex == s.size()) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i < s.size(); i++) {  // [startIndex,i]表示要截取的子串
			if (isPalindrome1(s, startIndex, i)) {
				path.push_back(s.substr(startIndex, i - startIndex + 1));
				backtracking(s, i + 1);
				path.pop_back();
			}		
		}
	}

	bool isPalindrome1(string& s, int begin, int end) {
		while (begin <= end) {
			if (s[begin++] != s[end--])
				return false;
		}
		return true;
	}
};

void main() {
	Solution st;
	string s("aab");
	vector<vector<string>> res = st.partition(s);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}
