#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		/*stack<string> stk;
		for (auto& s : tokens) {
			if (s == "+" || s == "-" || s == "*" || s == "/") {
				int temp1 = stoi(stk.top());
				stk.pop();
				int temp2 = stoi(stk.top());
				stk.pop();
				if (s == "+") temp2 += temp1;
				if (s == "-") temp2 -= temp1;
				if (s == "*") temp2 *= temp1;
				if (s == "/") temp2 /= temp1;
				stk.push(to_string(temp2));
			}
			else {
				stk.push(s);
			}
		}
		return stoi(stk.top());*/

		stack<int> stk;
		for (auto& s : tokens) {
			if (s == "+" || s == "-" || s == "*" || s == "/") {
				int num1 = stk.top();
				stk.pop();
				int num2 = stk.top();
				stk.pop();
				if (s == "+") stk.push(num2 + num1);
				if (s == "-") stk.push(num2 - num1);
				if (s == "*") stk.push(num2 * num1);
				if (s == "/") stk.push(num2 / num1);
			}
			else {
				stk.push(stoll(s));   //在这一步换成longlong 就不用再对其他的数操作了。
			}
		}
		return stk.top();
	}

	//第二次做
	int evalRPN1(vector<string>& tokens) {
		unordered_set<string> uset{ "+", "-", "*", "/" };
		stack<int> stk;
		for (string& s : tokens) {
			if (uset.find(s) == uset.end()) {
				stk.push(stoi(s));
			}
			else {
				int num1 = stk.top();
				stk.pop();
				int num2 = stk.top();
				stk.pop();
				if (s == "+")
					stk.push(num1 + num2);
				if (s == "-")
					stk.push(num2 - num1);
				if (s == "*")
					stk.push(num1 * num2);
				if (s == "/")
					stk.push(num2 / num1);
			}
		}
		return stk.top();
	}
};

int main() {
	Solution st;
	vector<string> tokens{ "2","1","+","3","*" };
	cout << st.evalRPN(tokens) << endl;
	return 0;
}
