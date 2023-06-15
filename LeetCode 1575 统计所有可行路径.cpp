/*
����һ��������ͬ���������飬�����еĵ�iλ��ʾ��i�����е�λ�ã�ͬʱ����start��finish��fuel�����ȼ�ͣ�ÿһ�ξ������ж�������ȼ�ͣ�
������֮���ȼ������������������Ԫ��֮��Ĳ�ľ���ֵ��ͬһ�����п��Ծ�����Σ�����·������������·�������ܴܺ��������10^9+7ȡ��
*/
#include <iostream>
#include <vector>
using namespace std;

//�ʼ�����������һ��dp���飬�����е�ÿһλ������start����һ�����ĵ�ȼ�ͣ��������ȼ���Ҳ����յ㣬Ȼ���ٴ���һ����������ϸ����̣�
//ֱ��ȼ��Ϊ0���ߵ����յ㣬���������ָо�̫����ʵ�ֲ��� ��  �ⲻ����dfs�� ��

class Solution {
public:
	int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		int n = locations.size();
		vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));  // *** dp[i][fuel]��ʾ��i�㿪ʼ����ǰ����Ϊfuel������µ����յ��·����
		return dfs(locations, dp, start, finish, fuel);
	}

	int dfs(vector<int>& locations, vector<vector<int>>& dp, int start, int end, int fuel) {
		if (dp[start][fuel] != -1) {
			return dp[start][fuel];
		}
		
		//��һ���������û����Ŀ�ĵأ�����û����
		if (start != end && fuel == 0) {
			dp[start][fuel] = 0;
			return 0;
		}

		//�ڶ����������û����Ŀ�ĵأ�������ʣ������Ѿ��������������ص���
		int n = locations.size();
		bool canArrive = false;
		for (int i = 0; i < n; i++) {
			if (i != start) {
				if (fuel >= abs(locations[i] - locations[start])) {
					canArrive = true;
					break;
				}
			}
		}
		if (fuel != 0 && canArrive == false) {
			dp[start][fuel] = start == end ? 1 : 0;
			return dp[start][fuel];
		}

		//�������ܵ�·��
		int sum = start == end ? 1 : 0;   //��Ϊ��Ŀ�����д���һ������������㹻ʱ�������յ�󻹿��Ե��������ڴ��������ٵ��յ�Ҳ��һ��·����
		for (int i = 0; i < n; i++) {
			if (i != start) {
				if (fuel >= abs(locations[i] - locations[start])) {
					sum += dfs(locations, dp, i, end, fuel - abs(locations[i] - locations[start]));
					sum %= 1000000007;   //��һ��д����������Ϊ��һ���������ر�࣬û����int��ʾ
				}
			}
		}
		dp[start][fuel] = sum;
		return sum;
	}
};

//�������dfs�Ͷ�̬�滮���ϵ�һ���⣬��ʼ��ʱ����ֻ�뵽��dfs������д�������룬�������˹�ˮ��Ҷ�Ĵ����֪����ôд�����ǻ��ǲ�������
int main() {
	vector<int> location1 = { 2,3,6,8,4 };
	int start1 = 1, finish1 = 3, fuel1 = 5;
	vector<int> location2 = { 4,3,1 };
	int start2 = 1, finish2 = 0, fuel2 = 6;
	Solution s;
	cout << s.countRoutes(location1, start1, finish1, fuel1) << endl;
	cout << s.countRoutes(location2, start2, finish2, fuel2) << endl;
	return 0;
}