#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//����һ���ַ���s����һ���ֵ�wordDict���ж��ַ���s�ܷ���wordDict�е�Ԫ��ƴ�ӳɣ�wordDict�еĵ��ʿ����ظ�ʹ�ã���Ҫ��ȫ����ʹ�ã��ܵ�ƴ�ӳɵĻ�����true�����򷵻�false��
//�������Ҫ������

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
};

int main() {
	Solution st;
	string s = "applepenapple";
	vector<string> wordDict = { "apple", "pen" };
	cout << boolalpha << st.wordBreak(s, wordDict) << noboolalpha << endl;
	return 0;
}