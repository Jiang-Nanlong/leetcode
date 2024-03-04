#include <iostream>
#include <vector>
using namespace std;

//���������ַ���������ʹ�������ַ�����ͬ����ɾ������С�ַ���
//��һ�ַ����ǰ���������¼��д�ģ�dp[i][j]��ʾ��i-1Ϊ��β���ַ���word1������j-1Ϊ��β���ַ���word2��Ҫ��ﵽ��ȣ�����Ҫɾ��Ԫ�ص���С����
//word1[i - 1] == word2[j - 1]ʱ�ĵ��ƹ�ʽ���룬���ǲ����ʱ�ĵ��ƹ�ʽ�е����룬
// ���Դ����������:
// һ�ǿ���ɾ��word1[i-1]����С��������dp[i-1][j]+1;
// ���ǿ���ɾ��word2[j-1]����С��������dp[i][j-1]+1;
// ����ͬʱɾ��word1[i-1]��word2[j-1]����С��������dp[i-1][j-1]+2

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
		for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;
		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}

	//��ʼ�����±����ַ������ģ��������ҳ������ַ����е�������Ӵ���Ȼ���������ַ����ĸ���ɾȥ������Ӵ��ĳ��Ⱦ���
	int minDistance1(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
	}
};

int main() {
	Solution st;
	string word1 = "leetcode", word2 = "etco";
	cout << st.minDistance(word1, word2) << endl;
	cout << st.minDistance1(word1, word2) << endl;
	return 0;
}