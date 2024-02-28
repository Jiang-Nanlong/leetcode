#include <iostream>
#include <vector>
using namespace std;

//�����ķ��������ر������ֻ�뵽��Ҫ�ö�ά��dp���飬һά��ʾ�����Ʊ������ֵ��һά��ʾ�����������ֵ
//��������Ժ��ֲ��������ģ�dp[i][0]��ʾ���й�Ʊ������ֵ��dp[i][1]��ʾ�����й�Ʊ������ֵ
//���й�Ʊ���Է�Ϊ������кͽ���������������������п��Է�Ϊ���첻���кͽ����������������
//��󷵻����һ�첻���й�Ʊ������ֵ
//�����ֻ������һ�ι�Ʊ����LeetCode 122 ������Ʊ�����ʱ��II�����������
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], -prices[i]);  //�������
			dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);   //���첻����
		}
		return dp[prices.size() - 1][1];
	}

	//�۲���ƹ�ʽ���Է��ֵ��������ֵֻ��ǰһ���йأ�����dp����ֻ��Ҫ���켴�ɡ�
	int maxProfit1(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);  //�����i%2�ͣ�i-1��%2�����������������Ҫ�ѽ����ֵ���¸���ǰһ�죬û�뵽��i%2����ֱ�ӽ���ʹ�����������
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
		}
		return dp[(prices.size() - 1) % 2][1];
	}

	//���⻹����̰������̰���޷Ǿ�����ͼ����룬��߼�����
	int maxProfit2(vector<int>& prices) {
		int low = INT_MAX;
		int result = 0;
		for (int i = 0; i < prices.size(); i++) {
			low = min(low, prices[i]);
			result = max(result, prices[i] - low);
		}
		return result;
	}
};

int main() {
	Solution st;
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit1(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
	return 0;
}