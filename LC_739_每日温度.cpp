#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//给定一个整数数组temperatures，返回一个数组res，res[i]表示temperatures[i]之后的第几天的温度会高于今天，如果没有更高的，res[i]=0；
//这里介绍了一种叫做单调栈的新方法，这个方法还算简单，栈内保存天数而非温度，从栈顶到栈底天数对应的气温递增，因为只有这样，当今天温度高于之前某天的温度时才会被记录。

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

	//第二次做，代码写的太复杂了
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

	//简化后
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