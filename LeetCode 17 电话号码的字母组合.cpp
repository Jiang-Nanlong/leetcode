#include <iostream>
#include <vector>
#include <string>
using namespace std;

//�����ٿ����������˼·�ϻ���ͦ�򵥵ģ���ΪҪ�õ�ѭ��������ҲҪ�л��ݣ�Ҫ��Ȼ��һ��ѭ���ͻ������ѭ�����ַ���
//�پ��ǵ�28 29�л�ȡ�����ڼ����ϵ��ַ������ȽϹؼ���

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