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

	//�ڶ���������˵�����LeetCode 131 �ָ���Ĵ���࣬����������ϸ�ڸ��࣬����û��������
	//������ǰ����е�ip��ַ�Ĺ���ж϶�������һ������ȥ����
	vector<string> res;

	vector<string> restoreIpAddresses1(string s) {
		backtracking(s, 0, 0);
		return res;
	}

	void backtracking(string& s, int startIndex, int pointNum) {
		if (pointNum == 3 && startIndex != s.size()) {  //startIndex!=s.size()�������������Ϊ�˷�ֹ�Ѿ����������㣬�������������s����������֡�
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
		if (end - begin + 1 > 3) //�����ԼӸ��жϣ����λ������3��ֱ�ӷ���false
			return false;

		if (s[begin] == '0' && begin != end)  //�ж�ǰ��0
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
	// ��������
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
		else if (end - start + 1 > 3) return false;  // ����һ����Ҫ��Ϊ������ֹ����ʱ�����ʣ������ֻ��ܶ��ֱ���˳���
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