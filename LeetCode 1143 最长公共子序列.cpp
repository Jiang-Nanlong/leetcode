#include <iostream>
#include <vector>
using namespace std;

//�ҳ���������������������еĳ��ȣ��������е���ĸ��һ���������ġ�
//��ʼ����Ϊ��LeetCode 300��718�������ϣ����Ǻ������ֵ��ƹ�ʽд���ˡ�
//������dp����ͺ��廹�ǱȽϺ���
//�����ĵ��ƹ�ʽ�Ƚ�����

class Solution {
public:
	//����ǰ���������¼�Ĵ���д�ã������ʼ��
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
		for (int i = 1; i <= text1.size(); i++) {
			for (int j = 1; j <= text2.size(); j++) {
				if (text1[i - 1] == text2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[text1.size()][text2.size()];
	}

	//�����Լ�д�ģ���ʼ���鷳��һ�㣬���ǿ�����˼·������
	int longestCommonSubsequence1(string text1, string text2) {
		vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
		if (text1[0] == text2[0]) dp[0][0] = 1;  //��һ����Ϊ�˷�ֹ��һ����ĸ��һ�������±�������ʼ����ʱ��i��0��ʼ���������Խ�������

		for (int i = 1; i < text1.size(); i++) {
			if (text1[i] == text2[0]) dp[i][0] = 1;
			else dp[i][0] = dp[i - 1][0];
		}
		for (int i = 1; i < text2.size(); i++) {
			if (text1[0] == text2[i]) dp[0][i] = 1;
			else dp[0][i] = dp[0][i - 1];
		}

		for (int i = 1; i < text1.size(); i++) {
			for (int j = 1; j < text2.size(); j++) {
				if (text1[i] == text2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[text1.size() - 1][text2.size() - 1];
	}
};

int main() {
	Solution st;
	string text1 = "abc", text2 = "def";
	cout << st.longestCommonSubsequence(text1, text2) << endl;
	cout << st.longestCommonSubsequence1(text1, text2) << endl;
	return 0;
}