#include <iostream>
#include <vector>
#include <string>
using namespace std;

//现在再看，这个题在思路上还是挺简单的，因为要用到循环，所以也要有回溯，要不然下一个循环就会包含本循环的字符。
//再就是第28 29行获取数字在键盘上的字符串，比较关键。

class Solution {
public:
	const string digitsmap[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return {};
		vector<string> res;
		string s;
		Helper(digits, 0, s, res);
		return res;
	}

	void Helper(string& digits, int startindex, string& cb, vector<string>& res) {
		if (startindex == digits.size()) {
			res.push_back(cb);
			return;
		}

		int index = digits[startindex] - '0';
		string temp = digitsmap[index];
		for (char c : temp) {
			cb.push_back(c);
			Helper(digits, startindex + 1, cb, res);
			cb.pop_back();
		}
	}
};

void main() {
	Solution st;
	vector<string> res = st.letterCombinations("234");
	for (auto& s : res)
		cout << s << endl;
}
