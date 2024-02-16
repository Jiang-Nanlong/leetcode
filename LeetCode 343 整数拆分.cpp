#include <iostream>
#include <vector>
using namespace std;

//��һ��������ֳɶ�����ĺͣ�Ȼ�󷵻���Щ���ĳ˻������ֵ
//���ݻ�������ʽ������Ҫ��ɼ������ô������Ӧ��һ���󣬻���˵�ǲ�������������Ҳ��һ����������Ӧ�þ����ܵ�һ����
//��ʵ�����dp������±�ĺ���ȽϺ���⣬������д���ƹ�ʽʱ����ʼ�����max(dp[i], j*dp[i-j])����������û�д����ǵ�i=3��Ҳ����
//��һ����ʱ�ͻᱨ��max(dp[i], j*dp[i-j])�Ľ����1��ʵ��Ӧ����2������ͳ����˵��ƹ�ʽ���
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 0, dp[1] = 0, dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j <= i / 2; j++) {  //ע��������i/2����Ϊǰһ��Ľ���ͺ�һ���ǶԳƵ�
				dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
				//dp[i] = max(dp[i], j * dp[i - j]);   //i=3ʱ�Ľ������
			}
		}
		for (auto c : dp)
			cout << c << " ";
		return dp[n];
	}
};

int main() {
	Solution st;
	int n = 10;
	cout << st.integerBreak(n) << endl;
	return 0;
}