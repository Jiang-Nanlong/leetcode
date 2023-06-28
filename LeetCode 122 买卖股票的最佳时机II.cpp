#include <iostream>
#include <vector>
using namespace std;

//ֻ��Ҫ����ÿ����֮�������Ȼ��������Ӽ���
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int m = prices.size(), result = 0;
		for (int i = 1; i < m; i++) {
			result += max(prices[i] - prices[i - 1], 0);
		}
		return result;
	}
};
int main() {
	vector<int> prices = { 7,1,5,3,6,4 };
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}