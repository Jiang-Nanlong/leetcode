#include <iostream>
#include <vector>
using namespace std;

//��������prices�е�prices[i]��ʾĳֻ��Ʊ��i��ļ۸�ÿ�춼����������Ʊ�������������
//�������̰���㷨����Ƚϼ򵥣�ֻ����Ǯ��׬����һ���ǵðѹ�Ʊ�������ܺü��죬�����߼۲�����
//ֻҪ����ļ۸����������е�׬����
//��̰���㷨�ĽǶ�Ҳ����⣬�ֲ����ţ�ÿ�춼��Ǯ׬  ȫ�����ţ�����������

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
};

void main() {
	Solution st;
	vector<int> prices{ 7,1,5,3,6,4 };
	cout << st.maxProfit(prices) << endl;
	cout << st.maxProfit2(prices) << endl;
}