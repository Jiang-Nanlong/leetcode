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
};

int main() {
	Solution st;
	vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector<int> res = st.dailyTemperatures(temperatures);
	for (auto i : res)
		cout << i << "  ";
	return 0;
}