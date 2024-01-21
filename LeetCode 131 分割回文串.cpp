#include <iostream>
#include <string>
#include <vector>
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