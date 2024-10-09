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


	// �����ڻ�������ר����ϰ����ˢ��������ˣ�������һ���ѵ���Ǻ�ʱ��С���ڣ�
	// ������ű������Ļ���Ҫһ�����Ŀ�t�еĸ���Ԫ�ص������ڵ�ǰ�������Ƿ������ˣ��������Ļ��Ϳ�����С�����ˡ�
	// �������ַ��������붼�ᳬʱ��
	// ������һ��cnt�ı������������ֻ����ͳ�ơ���Ҫ�ַ�����������Ҳ����˵��������ڵ�ǰԪ�ص�����С��t�и�Ԫ�ص�������
	// ˵����ǰ���Ԫ�������t��Ԫ�ص�һ����ҪԪ�أ��Ͱ�cnt++����������ڵĵ�ǰ�ַ�����Ŀ�Ѿ�������t�и��ַ�����������˵����ǰ�ַ�����һ����Ҫ���ַ���
	// ��cnt��t.size()��ͬʱ��˵�������Ѿ��չ���t�е�ÿ���ַ������ھͿ�����С�����ˡ������С�˴��ں󣬵�ǰ���ڵ��ڵĸ��ַ�������������t�и��ַ���������
	// ��˵����ǰ�ַ���һ����Ҫ���ַ�������cnt�͵ü�һ����ʱҲ��ֻ�������󴰿��ˡ�
	string minWindow1(string s, string t) {
		unordered_map<char, int> umap, umap2;
		for (char c : t)
			umap[c]++;

		int start = 0, minlen = INT_MAX;
		int cnt = 0;
		for (int i = 0, j = 0; j < s.size(); j++) {
			char c = s[j];
			if (umap.find(c) != umap.end()) {
				if (++umap2[c] <= umap[c])
					cnt++;
			}
			while (cnt == t.size()) {
				c = s[i];
				if (umap.find(c) != umap.end()) {
					if (--umap2[c] < umap[c])
						cnt--;
				}
				if (j - i + 1 < minlen) {
					start = i;
					minlen = j - i + 1;
				}
				i++;
			}
		}
		return minlen == INT_MAX ? "" : s.substr(start, minlen);
	}

	string minWindow2(string s, string t) {
		int count[128], window[128];
		memset(count, 0, sizeof(count));
		memset(window, 0, sizeof(window));

		for (char c : t)
			count[c]++;

		int start = 0, minlen = INT_MAX;
		int cnt = 0;
		for (int i = 0, j = 0; j < s.size(); j++) {
			char c = s[j];
			++window[c];
			if (count[c] >= window[c])
				cnt++;

			while (cnt == t.size()) {
				c = s[i];
				--window[c];
				if (window[c] < count[c])
					cnt--;
				if (j - i + 1 < minlen) {
					start = i;
					minlen = j - i + 1;
				}
				i++;
			}
		}
		return minlen == INT_MAX ? "" : s.substr(start, minlen);
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

	string res1 = st.minWindow1(s, t);
	for (auto& c : res1)
		cout << c << "  ";
	cout << endl;

	string res2 = st.minWindow2(s, t);
	for (auto& c : res2)
		cout << c << "  ";
	cout << endl;
	return 0;
}