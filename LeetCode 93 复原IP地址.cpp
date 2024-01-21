#include <iostream>
#include <string>
#include <vector>
using namespace std;
//�����Ҫ�ָ���ȷ��IP��ַ����LeetCode 131�ָ�����Ӵ��ѣ�����ط�Ҫ����'.'�����һ�������ǰ��0�ģ���֮ǰ��������·�ϻ���̫һ����
//������ǿ��Ĵ�������¼�Ĵ��룬�������ط���̫���ף���һ��������ֹ�������ΪʲôҪ��pointnum��
// �پ���forѭ�����break�����˵forѭ����������֮�䣬�����ǰ�ָ�Ĳ�������ߵĿ��ܺ����� �������Һ��������ˣ�isvalid����жϵ���ǰ��0������255�ģ������ǰ�����������㣬��ô�������ǻ᲻���㣬��������ָ�����Ͳ����Ǳ���֮��ķָ��ˡ�
//�о������е���

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

		for (int i = startindex; i < s.size() && i < startindex + 3; i++) {  //���Լ�һ��i < startindex + 3�����������Ͳ�����Ϊ������λ��������255����isValid��
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

	bool isValid(string& s, int begin, int end) {  //��Ҫ�ж�ǰ��0���Ƿ����255
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