#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

//����һ���ַ���s����s�ָ��һЩ�Ӵ���ʹ��ÿ���Ӵ����ǻ����Ӵ�������s�����зָ�������Ĵ��������Ŷ��ͷ��Ŷ�����һ�����ַ�����
//��ʼ��ʱ����������˫ָ���ж�һ���Ӵ��ǲ��ǻ��Ĵ��������ֵ����ǲ��ǻ��и�����ķ���������һ���ŷ��ֻ�������ôŪ��
//��������ת�������νṹ�����Բ����û��ݡ�

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
				string temp = s.substr(startindex, i - startindex + 1);  //��һ�������γ���Ĺؼ�
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


	//�ڶ�����������û�����ô��
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

		for (int i = startIndex; i < s.size(); i++) {  // [startIndex,i]��ʾҪ��ȡ���Ӵ�
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

	// ����������������ˮ��д������
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

	// ʹ�ö�̬�滮һ���Լ������Щ�ǻ����Ӵ����Ͳ���Ҫÿ�ζ�����isPalindrome���ж���
	// ����ط���LeetCode 647 �����Ӵ�һ����˼·
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