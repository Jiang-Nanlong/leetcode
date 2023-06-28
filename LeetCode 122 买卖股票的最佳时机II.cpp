#include <iostream>
#include <vector>
using namespace std;

//只需要计算每两天之间的利润，然后将正数相加即可
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