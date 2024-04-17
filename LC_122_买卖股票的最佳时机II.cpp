#include <iostream>
#include <vector>
using namespace std;

//��������prices�е�prices[i]��ʾĳֻ��Ʊ��i��ļ۸�ÿ�춼����������Ʊ�������������
//�������̰���㷨����Ƚϼ򵥣�ֻ����Ǯ��׬����һ���ǵðѹ�Ʊ�������ܺü��죬�����߼۲�����
//ֻҪ����ļ۸����������е�׬����
//��̰���㷨�ĽǶ�Ҳ����⣬�ֲ����ţ�ÿ�춼��Ǯ׬  ȫ�����ţ�����������

//������LeetCode 121 ������Ʊ�����ʱ�������������������������Σ���121��ֻ������һ��

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buy = prices[0];
		int result = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < buy)
				buy = prices[i];
			else {
				result = result + prices[i] - buy;
				buy = prices[i];
			}
		}
		return result;
	}

	//�򻯳�һ�´���
	int maxProfit1(vector<int>& prices) {
		int buy = prices[0];
		int result = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] > buy)
				result = result + prices[i] - buy;
			buy = prices[i];
		}
		return result;
	}

	//�±��Ǵ�������¼�Ĵ��룬���Ǵӵ�2�쿪ʼ���𣬺������ĸ�ֱ��
	int maxProfit2(vector<int>& prices) {
		int result = 0;
		for (int i = 1; i < prices.size(); i++) {
			result += max(prices[i] - prices[i - 1], 0);
		}
		return result;
	}

	//��̬�滮����dp[i][0]��ʾ��i����й�Ʊ������ֵ��dp[i][1]��ʾ��i�첻���й�Ʊ������ֵ
	int maxProfit3(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);  //��������һ����ƹ�ʽ��Ψһ��������⣬��i�����Ʊ��ʱ����ͷ������ֵ������ -prices[i]������dp[i-1][1]-prices[i]
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		return dp[prices.size() - 1][1];
	}

	//����121��һ�����Զ�dp��������Ż�
	int maxProfit4(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
			dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
		}
		return dp[(prices.size() - 1) % 2][1];
	}

	//�ڶ���������̰���㷨�½ڣ�ֱ���õĶ�̬�滮����
	int maxProfit5(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		//dp[i][0]���й�Ʊ������Ǯ��dp[i][1]�����й�Ʊ������Ǯ
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		return dp[prices.size() - 1][1];
	}

	//�ڶ���������̬�滮
	int maxProfit6(vector<int>& prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return dp[prices.size() - 1][0];
	}
};

void main() {
	Solution st;
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
	cout << st.maxProfit3(prices) << endl;
	cout << st.maxProfit4(prices) << endl;
}