#include <iostream>
#include <vector>
using namespace std;

//整数数组prices中的prices[i]表示某只股票第i天的价格，每天都可以买卖股票，返回最大利润
//这个题用贪心算法还算比较简单，只有有钱就赚，不一定非得把股票在手上攒好几天，遇到高价才卖。
//只要今天的价格相对于买价有得赚就卖
//从贪心算法的角度也好理解，局部最优：每天都有钱赚  全局最优：获得最大利润

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

	//简化成一下代码
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

	//下边是代码随想录的代码，它是从第2天开始算起，好像他的更直观
	int maxProfit2(vector<int>& prices) {
		int result = 0;
		for (int i = 1; i < prices.size(); i++) {
			result += max(prices[i] - prices[i - 1], 0);
		}
		return result;
	}
};

void main() {
	Solution st;
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
}