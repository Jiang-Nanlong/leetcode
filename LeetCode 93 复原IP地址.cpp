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
};

void main() {
	Solution st;
	string s("25525511135");
	vector<string> res = st.restoreIpAddresses(s);
	for (auto& s : res)
		cout << s << endl;
}