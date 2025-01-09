#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// ���������ַ���word1��word2������word1�е�ĳ�����ַ��������word2����������Ǹ��ַ�����ǰ׺����ô˵�����ַ�����һ���Ϸ��ַ��ܡ�
// ���غϷ��ַ�������Ŀ

// ��LeetCode 3298һģһ����ֻ�����������Ƚ�С
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

    // ֮����һ����������������Խ��Խ����Ļ��������⣬��������ֻ���뵽һ�����Ƚϴ��������ģʽ������
	long long validSubstringCount2(string word1, string word2) {
		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		int temp[26];
		memset(temp, 0, sizeof(temp));
		auto check = [&]() -> bool {
			for (int i = 0; i < 26; i++)
				if (temp[i] < count[i])
					return false;

			return true;
		};

		int n = word1.size();
		long long res = 0;

		for (int i = 0, j = 0; i <= j && j < n; j++) {
			temp[word1[j] - 'a']++;

			while (check()) {
				res += n - j;
				temp[word1[i++] - 'a']--;
			}
		}
		return res;
	}

        // ���˿�֮ǰд�Ĵ��룬�о��е����ֱ����һ������cnt��ͳ�Ʊ�Ҫ���ַ��ĸ�����һ����Ҫ�ַ��ĸ�����word2�ĳ�����ͬ�ˣ�˵�������ڵ�Ԫ���Ѿ����Դճ�������word2
	long long validSubstringCount3(string word1, string word2) {
		int count[26];
		memset(count, 0, sizeof(count));
		for (char c : word2)
			count[c - 'a']++;

		int temp[26];
		memset(temp, 0, sizeof(temp));

		int cnt = 0;
		int n = word1.size();
		long long res = 0;

		for (int i = 0, j = 0; i <= j && j < n; j++) {
			if (++temp[word1[j] - 'a'] <= count[word1[j] - 'a'])
				++cnt;

			while (cnt == word2.size()) {
				res += n - j;
				if (--temp[word1[i] - 'a'] < count[word1[i] - 'a'])
					--cnt;
				i++;
			}
		}
		return res;
	}
};

int main() {
	Solution st;
	string word1("abcabc"), word2("abc");
	cout << st.validSubstringCount(word1, word2) << endl;
	cout << st.validSubstringCount1(word1, word2) << endl;
	return 0;
}