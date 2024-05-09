#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//����һ����������temperatures������һ������res��res[i]��ʾtemperatures[i]֮��ĵڼ�����¶Ȼ���ڽ��죬���û�и��ߵģ�res[i]=0��
//���������һ�ֽ�������ջ���·����������������򵥣�ջ�ڱ������������¶ȣ���ջ����ջ��������Ӧ�����µ�������Ϊֻ���������������¶ȸ���֮ǰĳ����¶�ʱ�Żᱻ��¼��

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<int> stk;
		vector<int> res(temperatures.size(), 0);
		for (int i = 0; i < temperatures.size(); i++) {
			while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
				res[stk.top()] = i - stk.top();
				stk.pop();
			}
			stk.push(i);
		}
		return res;
	}

	//�ڶ�����������д��̫������
	vector<int> dailyTemperatures1(vector<int>& temperatures) {
		stack<int> stk;
		vector<int> res(temperatures.size(), 0);

		for (int i = 0; i < temperatures.size(); i++) {
			if (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
				while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
					res[stk.top()] = i - stk.top();
					stk.pop();
				}
				stk.push(i);
			}
			else if (stk.empty() ||
				temperatures[stk.top()] >= temperatures[i]) {
				stk.push(i);
			}
		}
		return res;
	}

	//�򻯺�
	vector<int> dailyTemperatures2(vector<int>& temperatures) {
		stack<int> stk;
		vector<int> res(temperatures.size(), 0);

		for (int i = 0; i < temperatures.size(); i++) {
			while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
				res[stk.top()] = i - stk.top();
				stk.pop();
			}
			stk.push(i);
		}
		return res;
	}
};

int main() {
	Solution st;
	vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> res = st.dailyTemperatures(temperatures);
	for (auto i : res)
		cout << i << "  ";
	cout << endl;
	vector<int> res1 = st.dailyTemperatures1(temperatures);
	for (auto i : res1)
		cout << i << "  ";
	cout << endl;
	vector<int> res2 = st.dailyTemperatures2(temperatures);
	for (auto i : res2)
		cout << i << "  ";
	return 0;
}