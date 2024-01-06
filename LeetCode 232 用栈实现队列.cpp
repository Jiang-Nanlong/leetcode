#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
	MyQueue() {

	}

	void push(int x) {
		while (!outstk.empty()) {
			instk.emplace(outstk.top());
			outstk.pop();
		}
		instk.emplace(x);
	}

	int pop() {
		if (outstk.empty()) {
			while (!instk.empty()) {
				outstk.push(instk.top());
				instk.pop();
			}
		}
		int res = outstk.top();
		outstk.pop();
		return res;
	}

	int peek() {
		int res = this->pop();
		outstk.push(res);
		return res;
	}

	bool empty() {
		return instk.empty() && outstk.empty();
	}
private:
	stack<int> instk, outstk;
};

void main() {

}