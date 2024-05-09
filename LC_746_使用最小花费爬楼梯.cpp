#include <iostream>
#include <vector>
using namespace std;

//�����տ�ʼ����ʱ���һ����벻����ô�ö�̬�滮�������ǿ�����Ƶ��ķ���������������
//dp[i]�������i��̨�׵���С���ѣ���ô��i��̨�׿��Դӵ�i-1��̨����һ��������Ҳ���Դӵ�i-2��̨�������������������ͺ�����ȷ�����ƹ�ʽ��
//��Ϊ�ʼ���Դӵ�0��̨�׻��ߵ�1��̨�������������������dp[0]��dp[1]����ʼ��Ϊ0.
//���⻹��һ���ط���Ҫע�⣬����¥�ݵĶ����������һ��̨��֮��Ȼ����Ŀ��ÿ��̨�׵Ļ�����ʵ�Ǳ�ʾ�ӵ�ǰ̨�������Ļ��ѣ��������������̨�׵Ļ��ѡ�
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> dp(cost.size() + 1, 0);
		for (int i = 2; i <= cost.size(); i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[cost.size()];
	}

	//�ڶ���������ε�dp[i]��ʾ���Ǵӵ�i��̨����������Ҫ���ѵ���СǮ����Ȼ��ÿһ������1��2��̨�ף���ô������Ͽ���ͨ��n-1��n-2һ������ȥ��ȡ��Сֵ����
	int minCostClimbingStairs1(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n, 0);
		dp[0] = cost[0], dp[1] = cost[1];
		for (int i = 2; i < n; i++) {
			dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
		}
		return min(dp[n - 1], dp[n - 2]);
	}

	//��һ��д����dp[i]��ʾ������i��̨������Ҫ����С����
	int minCostClimbingStairs2(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[n];
	}

};

int main() {
	Solution st;
	vector<int> cost{ 1,100,1,1,1,100,1,1,100,1 };
	cout << st.minCostClimbingStairs(cost) << endl;
	return 0;
}
