/*
n������վ��һ�ţ�ÿ���������ٷ���һ���ǹ������ڵ������������ָ��ߵĺ��ӻ�ø�����ǹ����������ٵ��ǹ���Ŀ��
�ʼ��ʱ������Ϊ������ķ������ӵ͵��ߣ�������͵��˷�һ����Ȼ�����ε���������������Υ����֮ǰÿ���˵�λ�ã��͸ı������������
ͬʱ����ʵ��[1,0,2]������Ҫ2��1��2��һ��5���ǹ���Ȼ����LeetCode101�����и���һ���ر�������㷨��
��Ϊÿ�����Ӷ�����Ҫ���һ���ǹ���Ȼ������Ͱ�ÿ���˵��ǹ����1��Ȼ��������ұ���������ұߺ��Ӵ�����ߣ����ұߺ��ӵ��ǹ���������ߺ����ǹ���+1��
Ȼ�������������������ߺ������ִ����ұߺ��ӣ����ǹ������ڻ�����ұߣ�����ߺ��ӵ��ǹ��������ұߵ�+1
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int m = ratings.size();
		if (m < 2) return m;     //����LeetCode101����ģ����Լӿ��ٶ�
		vector<int> sweets(m, 1);
		for (int i = 0; i + 1 < m; i++) {
			if (ratings[i] < ratings[i + 1])
				sweets[i + 1] = sweets[i] + 1;
		}
		for (int i = m - 1; i - 1 >= 0; i--) {
			if (ratings[i - 1] > ratings[i] && sweets[i - 1] <= sweets[i]) {
				sweets[i - 1] = sweets[i] + 1;
			}
		}
		/*int sweet = 0;
		for (int i : sweets)
			sweet += i;
		return sweet;*/
		return accumulate(sweets.begin(), sweets.end(), 0);  //����������д
	}
};

int main() {
	vector<int> ratings1 = { 1,0,2 };
	vector<int> ratings2 = { 1,2,2 };
	Solution s;
	cout << s.candy(ratings1) << endl;
	cout << s.candy(ratings2) << endl;
	return 0;
}