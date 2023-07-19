/*
* ����ͨ�Ĺ�Ʊ����һ��������ÿ�ʽ��׶���Ҫ��������
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int res = 0, minprice = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] < minprice)    //��ǰ�۸��minprice��С��ֱ������
				minprice = prices[i];
			if (prices[i] > minprice && prices[i] < minprice + fee) continue;    //��ǰ�۸�֧���������ѾͲ���Ǯ�ˣ�ֱ������
			if (prices[i] > minprice + fee) {
				res += prices[i] - minprice - fee;
				minprice = prices[i] - fee;	//Ϊ�˱��⵱ǰ�ڵ�ֻ����������е�һ�Σ����Լ�ȥfee��ѭ����һ���൱���ټ���fee
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