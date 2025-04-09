//
// Created by cml on 25-4-9.
//
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<pair<int, int> > stk;

public:
    MinStack() {
        stk.emplace(0,INT_MAX);
    }

    void push(int val) {
        stk.emplace(val, min(getMin(), val));
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};

int main() {
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}
