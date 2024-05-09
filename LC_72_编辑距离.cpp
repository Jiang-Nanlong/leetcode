#include <iostream>
#include <vector>
using namespace std;

//���������ַ���word1��word2�����ذ�word1���word2����С�����������Բ����ַ���ɾ���ַ����滻�ַ���
//������dp����ͳ�ʼ������word1[i - 1] == word2[j - 1]�ĵ��ƹ�ʽ��ͦ���롣
//����word1[i - 1] != word2[j - 1]ʱ�ĵ��ƹ�ʽ����ֻ�����dp[i - 1][j - 1] + 1��dp[i - 1][j] + 1��û�뵽dp[i][j-1]+1����Ϊ����ֻ���޸�word1����Ӧ���޸�word2
//��dp[i][j-1]+1������word2�Ļ������޸ģ����Ǻ���������Ƶ�����ף�word2���Ԫ���൱��word1ɾ��һ��Ԫ�أ�word2ɾ��һ��Ԫ���൱��word1���һ��Ԫ�أ������������word1��ab  word2��a
//������word1[i - 1] != word2[j - 1]ʱ����Ϊ���������
//0.word1��ӻ�ɾ��һ��Ԫ�ر��word2����dp[i-1][j]+1��
//1.word2��ӻ�ɾ��һ��Ԫ�ر��word2����dp[i][j-1]+1��
//2.word1�޸�һ��Ԫ�ر��word2����dp[i-1][j-1]+1;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;
		for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;

		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else {
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
				}
			}
		}
		return dp[word1.size()][word2.size()];
	}

	//�ڶ����������ǲ��ᣬ����ⲻ��ͬʱ�ĵ��ƹ�ʽ������
	// dp[i-1][j-1]+1��ʾ�滻һ����ǰԪ��
	// dp[i - 1][j] + 1, dp[i][j - 1] + 1�ֱ��ʾɾ��word1�еĵ�ǰԪ�غ�ɾ��word2�е�ǰԪ��
	int minDistance1(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word1.size(); i++)
			dp[i][0] = i;
		for (int i = 0; i <= word2.size(); i++)
			dp[0][i] = i;

		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
		return dp[word1.size()][word2.size()];
	}
};

int main() {
	Solution st;
	string word1 = "horse", word2 = "ros";
	cout << st.minDistance(word1, word2) << endl;
	return 0;
}