#include <iostream>
#include <string>
#include <vector>
#include <functional>
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

	// 第三次做，行云流水的写出来了
	vector<vector<string>> partition2(string s) {
		path.clear();
		res.clear();
		backtracking2(s, 0);
		return res;
	}
	void backtracking2(string& s, int start) {
		if (start == s.size()) {
			res.push_back(path);
			return;
		}

		for (int i = start; i < s.size(); i++) {
			if (isPalindrome2(s, start, i)) {
				string str = s.substr(start, i - start + 1);
				path.push_back(str);
				backtracking2(s, i + 1);
				path.pop_back();
			}
		}
	}

	bool isPalindrome2(string& s, int begin, int end) {
		while (begin <= end) {
			if (s[begin++] != s[end--])
				return false;
		}
		return true;
	}

	// 使用动态规划一次性计算出哪些是回文子串，就不需要每次都调用isPalindrome来判断了
	// 这个地方和LeetCode 647 回文子串一样的思路
	vector<vector<bool>> dp;

	vector<vector<string>> partition3(string s) {
		path.clear();
		res.clear();
		isPalindrome3(s);
		backtracking3(s, 0);
		return res;
	}
	void backtracking3(string& s, int start) {
		if (start == s.size()) {
			res.push_back(path);
			return;
		}

		for (int i = start; i < s.size(); i++) {
			if (dp[start][i]) {
				string str = s.substr(start, i - start + 1);
				path.push_back(str);
				backtracking3(s, i + 1);
				path.pop_back();
			}
		}
	}

	void isPalindrome3(string& s) {
		dp.resize(s.size(), vector<bool>(s.size(), false));
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i; j < s.size(); j++) {
				if (s[i] == s[j]) {
					if (j - i <= 1)
						dp[i][j] = true;
					else if (dp[i + 1][j - 1])
						dp[i][j] = true;
				}
			}
		}
	}
};

class Solution1 {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> path;
		int n = s.size();

		function<void(int)> dfs = [&](int begin) {
			if (begin == n) {
				res.push_back(path);
				return;
			}

			for (int end = begin; end < n; end++) {
				if (isValid(s, begin, end)) {
					path.push_back(s.substr(begin, end - begin + 1));
					dfs(end + 1);
					path.pop_back();
				}
			}
		};
		dfs(0);
		return res;
	}

	bool isValid(const string& s, int left, int right) {
		while (left <= right)
			if (s[left++] != s[right--])
				return false;
		return true;
	}
};


class Solution2 {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> path;

		auto isValid = [](const string& a) {
			int i = 0, j = a.size() - 1;
			while (i <= j) {
				if (a[i++] != a[j--])
					return false;
			}
			return true;
		};

		function<void(int)> dfs = [&](int i)->void{
			if (i == s.size()) {
				res.push_back(path);
				return;
			}
			for (int j = i; j < s.size(); j++) {
				string substr = s.substr(i, j - i + 1);
				if (isValid(substr)) {
					path.push_back(substr);
					dfs(j + 1);
					path.pop_back();
				}
			}
		};
		dfs(0);
		return res;
	}
};

int main() {
	Solution st;
	string s("aab");
	vector<vector<string>> res = st.partition(s);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	cout << "-----------" << endl;
	vector<vector<string>> res1 = st.partition2(s);
	for (int i = 0; i < res1.size(); i++) {
		for (int j = 0; j < res1[i].size(); j++)
			cout << res1[i][j] << " ";
		cout << endl;
	}

	cout << "-----------" << endl;
	vector<vector<string>> res3 = st.partition3(s);
	for (int i = 0; i < res3.size(); i++) {
		for (int j = 0; j < res3[i].size(); j++)
			cout << res3[i][j] << " ";
		cout << endl;
	}
	return 0;
}