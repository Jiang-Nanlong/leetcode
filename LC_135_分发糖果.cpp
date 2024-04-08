#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//�±�����֮ǰ���˳���ʱ������
/*
n������վ��һ�ţ�ÿ���������ٷ���һ���ǹ������ڵ������������ָ��ߵĺ��ӻ�ø�����ǹ����������ٵ��ǹ���Ŀ��
�ʼ��ʱ������Ϊ������ķ������ӵ͵��ߣ�������͵��˷�һ����Ȼ�����ε���������������Υ����֮ǰÿ���˵�λ�ã��͸ı������������
ͬʱ����ʵ��[1,0,2]������Ҫ2��1��2��һ��5���ǹ���Ȼ����LeetCode101�����и���һ���ر�������㷨��
��Ϊÿ�����Ӷ�����Ҫ���һ���ǹ���Ȼ������Ͱ�ÿ���˵��ǹ����1��Ȼ��������ұ���������ұߺ��Ӵ�����ߣ����ұߺ��ӵ��ǹ���������ߺ����ǹ���+1��
Ȼ�������������������ߺ������ִ����ұߺ��ӣ����ǹ������ڻ�����ұߣ�����ߺ��ӵ��ǹ��������ұߵ�+1
*/
/*
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
		*/
		/*int sweet = 0;
		for (int i : sweets)
			sweet += i;
		return sweet;*/
		/*
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
		*/

		//����ǿ��Ĵ�������¼�Ĵ��룬˼·��֮ǰ��һ���ģ���Ҳ̫�����ˣ������Խת��
class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> count(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1])
				count[i] = count[i - 1] + 1;
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				count[i] = max(count[i + 1] + 1, count[i]);
		}
		int sum = 0;
		for (int i : count)
			sum += i;
		return sum;
	}

	//�ڶ�����
	//���˼·���У�����������ȷ�Ĵ𰸣���Ϊ�ڴ����������ʱ����ʱ����count[i]�Ѿ��Ǵ���count[i+1]���ˣ�Ҳ�Ͳ���Ҫ�Ķ���
	int candy1(vector<int>& ratings) {  //˼·����
		if (ratings.size() == 1) return 1;
		int count = ratings.size();
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1])
				count++;
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				count++;
		}
		return count;
	}

	//�������ȷ�Ĵ�
	int candy2(vector<int>& ratings) {
		if (ratings.size() == 1) return 1;
		vector<int> count(ratings.size(), 1);

		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) {
				count[i] = count[i - 1] + 1;
			}
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1])
				count[i] = max(count[i], count[i + 1] + 1);
		}
		return accumulate(count.begin(), count.end(), 0);
	}
};

int main() {
	Solution st;
	vector<int> ratings{ 1,3,2,2,1 };
	int sum = st.candy(ratings);
	cout << sum << endl;
	cout << st.candy2(ratings) << endl;
	return 0;
}