#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//����һ������stone��stones[i]��ʾ��i��ʯͷ��������һ���Դ�������ȡ������ʯͷx��y��x<=y�����x==y����ô����ʯͷ�ᱻ��ȫ���飬
//���x!=y����ôx�ᱻ��ȫ���飬������Ϊy��ʯͷ��������Ϊy-x���������ʣ���ʯͷ��������С����
//������һ������������ô�Ǳ������⣬������ʾ��֪������ȫ���Գ���Ϊ��stones[i]ǰ���+ -�ţ�ʹ�����ĺ���С��
//Ȼ��Ҳ���԰�sum/2�������������������е��������ܵ�����������������sum��ż�����ұ����������ˣ���ô������0�����sum�������������������ˣ���ô�����1��
//������ת�����˱������⣬����ÿ������ֻ����һ�Σ����Ծ���01����
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) { //��һά����������֮ǰһ������·��һ����ģ�棬���ǲ������
		int sum = 0;
		for (int& i : stones)
			sum += i;
		int target = sum / 2;
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++)
			for (int j = target; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}

		return sum - 2 * dp[target];
	}

	int lastStoneWeightII1(vector<int>& stones) {   //�ö�ά���������߼��ϸ�����һЩ
		int sum = 0;
		for (const int& i : stones)
			sum += i;
		int bagsize = sum / 2 + 1;
		vector<vector<int>> dp(stones.size(), vector<int>(bagsize, 0));
		for (int i = stones[0]; i < bagsize; i++)
			dp[0][i] = stones[0];

		for (int i = 1; i < stones.size(); i++) {
			for (int j = 0; j < bagsize; j++) {
				if (j < stones[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
			}
		}
		return sum - dp[stones.size() - 1][bagsize - 1] * 2;
	}

	//�ڶ�����������û��������û���������ô��һ����������
	int lastStoneWeightII2(vector<int>& stones) {
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int target = sum / 2;
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++) {
			for (int j = target; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		return sum - 2 * dp[target];
	}

	// ����������������ͳ�Ƴ�ʯͷһ�������Ȼ�󿴿�ʯͷ������һ���С�ı������װ���١�
	int lastStoneWeightII3(vector<int>& stones) {
		int sum = accumulate(stones.begin(), stones.end(), 0);
		int bagsize = sum / 2;
		vector<int> dp(bagsize + 1, 0);
		for (int i = 0; i < stones.size(); i++) {
			for (int j = bagsize; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		return sum - 2 * dp[bagsize];
	}

};

int main() {
	Solution st;
	vector<int> stones{ 2,7,4,1,8,1 };
	cout << st.lastStoneWeightII1(stones) << endl;
	cout << st.lastStoneWeightII2(stones) << endl;
	cout << st.lastStoneWeightII3(stones) << endl;
	return 0;
}