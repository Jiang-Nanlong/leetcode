#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// ���������ַ���word1��word2������word1�е�ĳ�����ַ��������word2����������Ǹ��ַ�����ǰ׺����ô˵�����ַ�����һ���Ϸ��ַ��ܡ�
// ���غϷ��ַ�������Ŀ

class Solution {
public:
	long long validSubstringCount(string word1, string word2) {
		if (word1.size() < word2.size()) return 0;

		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		long long res = 0;
		int cnt = 0, n = word1.size();  // ���Ǻ�76��һ������cnt����¼��Ҫ�ַ�����Ŀ
		int window[26];
		memset(window, 0, sizeof(window));
		for (int i = 0, j = 0; j < n; j++) {
			int index = word1[j] - 'a';
			if (++window[index] <= count[index])
				++cnt;
			while (cnt == word2.size()) {
				res += n - j; // �����ǰ��i��ͷ��j��β���ַ����ǺϷ��ģ���ô��j��������ַ���β���ַ���Ҳ���ǺϷ���
				index = word1[i] - 'a';
				if (--window[index] < count[index])
					cnt--;
				i++;
			}
		}
		return res;
	}

	// һ�����������ϱ�ͳ�Ƶ�����iΪ��˵㣬�Բ�ͬ�Ҷ˵�Ϊ��β�����ַ�������Ŀ
	// �±�ͳ�Ƶ�����jΪ�Ҷ˵㣬�Բ�ͬ��˵㿪ʼ�����ַ�������Ŀ
	long long validSubstringCount1(string word1, string word2) {
		if (word1.size() < word2.size())
			return 0;
		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		long long res = 0;
		int cnt = 0, n = word1.size();
		int window[26];
		memset(window, 0, sizeof(window));
		for (int i = 0, j = 0; j < n; j++) {
			int index = word1[j] - 'a';
			if (++window[index] <= count[index])
				++cnt;
			while (cnt == word2.size()) {
				index = word1[i] - 'a';
				if (--window[index] < count[index])
					cnt--;
				i++;
			}
			res += i;
		}
		return res;
	}

        // ��������һ����һģһ����ֻ�������ݷ�Χ��ͬ
};

int main() {
	Solution st;
	string word1("abcabc"), word2("abc");
	cout << st.validSubstringCount(word1, word2) << endl;
	cout << st.validSubstringCount1(word1, word2) << endl;
	return 0;
}