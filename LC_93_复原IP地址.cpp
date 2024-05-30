#include <iostream>
#include <string>
#include <vector>
using namespace std;
//这个题要分割正确的IP地址，比LeetCode 131分割回文子串难，这个地方要插入'.'，而且还不能是前导0的，跟之前的题在套路上还不太一样。
//这个题是看的代码随想录的代码，有两个地方不太明白，第一个就是终止条件这里，为什么要用pointnum，
// 再就是for循环里的break这里，按说for循环是在树层之间，如果当前分割的不合理，后边的可能合理。奥 ，这里我好像明白了，isvalid里边判断的是前导0，大于255的，如果当前这两个不满足，那么再往后还是会不满足，所以这个分割不合理，就不考虑本层之后的分割了。
//感觉这里有点绕

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		Helper(s, 0, 0, res);
		return res;
	}
	void Helper(string& s, int startindex, int pointnum, vector<string>& res) {
		if (pointnum == 3) {
			if (isValid(s, startindex, s.size() - 1))
				res.push_back(s);
			return;
		}

		for (int i = startindex; i < s.size() && i < startindex + 3; i++) {  //可以加一个i < startindex + 3条件，这样就不会因为超过三位数而超过255而进isValid了
			if (isValid(s, startindex, i)) {
				s.insert(s.begin() + i + 1, '.');
				pointnum++;
				Helper(s, i + 2, pointnum, res);
				pointnum--;
				s.erase(s.begin() + i + 1);
			}
			else break;
		}
	}

	bool isValid(string& s, int begin, int end) {  //主要判断前导0和是否大于255
		if (begin > end) return false;
		if (s[begin] == '0' && begin != end) return false;
		int num = 0;
		for (int i = begin; i <= end; i++) {
			if (s[i] > '9' || s[i] < '0') return false;
			num = num * 10 + s[i] - '0';
			if (num > 255) return false;
		}
		return true;
	}

	//第二次做，虽说这个和LeetCode 131 分割回文串差不多，但是这个题的细节更多，还是没有做出来
	//这个题是把所有的ip地址的规格判断都放在了一个函数去处理
	vector<string> res;

	vector<string> restoreIpAddresses1(string s) {
		backtracking(s, 0, 0);
		return res;
	}

	void backtracking(string& s, int startIndex, int pointNum) {
		if (pointNum == 3 && startIndex != s.size()) {  //startIndex!=s.size()这个条件是用来为了防止已经加了三个点，而第三个点加在s最后的情况出现。
			if (isValid1(s, startIndex, s.size() - 1))
				res.push_back(s);
			return;
		}

		for (int i = startIndex; i < s.size(); i++) {
			if (isValid1(s, startIndex, i)) {
				s.insert(s.begin() + i + 1, '.');
				backtracking(s, i + 2, pointNum + 1);
				s.erase(s.begin() + i + 1);
			}
		}
	}

	bool isValid1(string& s, int begin, int end) {
		if (end - begin + 1 > 3) //还可以加个判断，如果位数超过3就直接返回false
			return false;

		if (s[begin] == '0' && begin != end)  //判断前导0
			return false;

		int num = 0;
		for (int i = begin; i <= end; i++) {
			num = num * 10 + (s[i] - '0');
			if (num > 255)
				return false;
		}
		return true;
	}

public:
	// 第三次做
	vector<string> restoreIpAddresses2(string s) {
		res.clear();
		if (s.size() < 4) return{};
		backtracking2(s, 0, 0);
		return res;
	}

	void backtracking2(string& s, int start, int pointnum) {
		if (pointnum == 3 && isValid2(s, start, s.size() - 1)) {
			res.push_back(s);
			return;
		}
		for (int i = start; i < s.size(); i++) {
			if (i - start < 3 && isValid2(s, start, i)) {
				s.insert(s.begin() + i + 1, '.');
				backtracking2(s, i + 2, pointnum + 1);
				s.erase(i + 1, 1);
			}
		}
	}

	bool isValid2(string& s, int start, int end) {
		if (start > end) return false;
		else if (end - start + 1 > 3) return false;  // 加这一句主要是为了在终止条件时，如果剩余的数字还很多就直接退出了
		else if (end - start >= 1 && s[start] == '0') return false;

		string str = s.substr(start, end - start + 1);
		long long num = stoi(str);
		if (num > 255)return false;
		return true;
	}
};

int main() {
	Solution st;
	string s("25525511135");
	vector<string> res = st.restoreIpAddresses(s);
	for (auto& s : res)
		cout << s << endl;

	cout << "---------" << endl;
	string s1("0279245587303");
	vector<string> res1 = st.restoreIpAddresses2(s1);
	for (string& s : res1)
		cout << s << endl;
	return 0;
}