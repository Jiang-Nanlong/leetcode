#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//����һ���ַ���s����һ���ֵ�wordDict���ж��ַ���s�ܷ���wordDict�е�Ԫ��ƴ�ӳɣ�wordDict�еĵ��ʿ����ظ�ʹ�ã���Ҫ��ȫ����ʹ�ã��ܵ�ƴ�ӳɵĻ�����true�����򷵻�false��
//�������Ҫ������
//�о�������е��ѣ���̫��������Ǳ�������

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {  //��������������һ�����������ı�������ͷ������Щ��Ʒ������������Ա�����װ������Ϊtrue
			for (int j = 0; j < i; j++) {  //������Ʒ
				string word = s.substr(j, i - j);
				if (wordSet.find(word) != wordSet.end() && dp[j] == true) {  //�о�������ƹ�ʽ�е�����
					dp[i] = true;
				}
			}
		}
		return dp[s.size()];
	}

	//�ȱ�����Ʒ�ٱ������������ֲ��У�������û��������Ϊʲô����
	bool wordBreak1(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int j = 0; j < wordDict.size(); j++) { // ��Ʒ
			for (int i = wordDict[j].size(); i <= s.size(); i++) { // ����
				string word = s.substr(i - wordDict[j].size(), wordDict[j].size());
				cout << word << endl;
				if (word == wordDict[j] && dp[i - wordDict[j].size()]) {
					dp[i] = true;
				}
				for (int k = 0; k <= s.size(); k++)
					cout << dp[k] << " ";
				cout << "---------------------" << endl;
			}
		}
		return dp[s.size()];
	}

	//�ڶ�����������û����������û��������ĵ��ƹ�ʽ������������������Ʒ��ʱ���֮ǰҲ��һ��
	bool wordBreak2(string s, vector<string>& wordDict) {
		unordered_set<string> uset(wordDict.begin(), wordDict.end());
		vector<bool>dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 0; j < i; j++) {
				string word = s.substr(j, i - j);
				if (uset.find(word) != uset.end() && dp[j] == true)
					dp[i] = true;
			}
		}
		return dp[s.size()];
	}
};

int main() {
	Solution st;
	string s = "applepenapple";
	vector<string> wordDict = { "apple", "pen" };
	cout << boolalpha << st.wordBreak1(s, wordDict) << noboolalpha << endl;
	return 0;
}