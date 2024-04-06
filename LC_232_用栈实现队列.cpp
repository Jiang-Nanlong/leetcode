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


//µÚ¶þ´Î×ö
class MyQueue1 {
public:
	MyQueue1() {}

	void push(int x) { inStk.push(x); }

	int pop() {
		if (outStk.empty()) {
			while (!inStk.empty()) {
				outStk.push(inStk.top());
				inStk.pop();
			}
		}
		int res = outStk.top();
		outStk.pop();
		return res;
	}

	int peek() {
		int res = this->pop();
		outStk.push(res);
		return res;
	}

	bool empty() { return inStk.empty() && outStk.empty(); }

private:
	stack<int> inStk, outStk;
};
void main() {

}
