#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
	//public:
	//	string minWindow(string s, string t) {
	//		int i = 0, j = 0, k = 0, count = INT_MAX;
	//		unordered_map<char, int> tump, sump;
	//		for (auto& c : t) tump[c]++;
	//		for (; j < s.size(); j++) {
	//			sump[s[j]]++;
	//			while (compareUnorderedmap(sump, tump, t)) {
	//				sump[s[i]]--;
	//				if (sump[s[i]] == 0) {
	//					sump.erase(s[i]);
	//				}
	//				/*k = i;
	//				count = min(count, j - i + 1);*/
	//				if ((j - i + 1) <= count) {
	//					k = i;
	//					count = (j - i + 1);
	//				}
	//				i++;
	//			}
	//		}
	//		return count == INT_MAX ? "" : s.substr(k, count);
	//	}
	//private:
	//	bool compareUnorderedmap(unordered_map<char, int>& a, unordered_map<char, int>& b, string& t) {
	//		if (a.size() >= b.size()) {
	//			for (auto& c : t) {
	//				if (a[c] < b[c]) return false;
	//			}
	//			return true;
	//		}
	//		else return false;
	//	}
	//�ϱ������Լ�д�ģ�ģ����֮ǰ�Ļ������ڵ��⣬д��һ��ר�ŵıȽϺ������Ƚϣ����������s��t���ر���ʱ������г�ʱ�ˡ�
	//��߿��˴�������¼�Ĵ����д�����ģ����ǻ���Ū��̫��
public:
	string minWindow(string s, string t) {
		int i = 0, j = 0, cnt = 0, k = 0, count = INT_MAX;
		unordered_map<char, int> sump, tump;
		for (auto& c : t) tump[c]++;
		for (; j < s.size(); j++) {
			sump[s[j]]++;
			if (sump[s[j]] <= tump[s[j]]) cnt++;
			while (sump[s[i]] > tump[s[i]]) sump[s[i++]]--;
			if (cnt == t.size() && (j - i + 1) <= count) {
				k = i;
				count = (j - i + 1);
			}
		}
		return count == INT_MAX ? "" : s.substr(k, count);
	}
};

//�о�����������ж���С���ں�ȷ��ÿ���������ǲ��ǰ�����t�����е��ַ����������ط���д���ر���
//�ֿ��˼�������д�Ĵ��룬�Ի�����������һ������ˣ�˼·����˫ָ�룬������С���ڵ��������ж�ÿ�������Ƿ����Ҫ��Ҫ�������

int main() {
	Solution st;
	string s("cabwefgewcwaefgcf"), t("cae");
	string res = st.minWindow(s, t);
	for (auto& c : res)
		cout << c << "  ";
	cout << endl;
	return 0;
}