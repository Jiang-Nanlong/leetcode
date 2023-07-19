/*
* 和普通的股票交易一样，但是每笔交易都需要付手续费
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int res = 0, minprice = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] < minprice)    //当前价格比minprice还小，直接买入
				minprice = prices[i];
			if (prices[i] > minprice && prices[i] < minprice + fee) continue;    //当前价格支付完手续费就不挣钱了，直接跳过
			if (prices[i] > minprice + fee) {
				res += prices[i] - minprice - fee;
				minprice = prices[i] - fee;	//为了避免当前节点只是这个区间中的一段，所以减去fee，循环下一次相当于再加上fee
			}
		}
		return res;
	}
};

int main() {
	vector<int> prices = { 1,3,2,8,4,9 };
	vector<int> prices1 = { 1,2,3,4,5,6,7,4,9 };
	int fee = 2;
	Solution s;
	cout << s.maxProfit(prices, fee) << endl;
	cout << s.maxProfit(prices1, fee) << endl;
	return 0;
}