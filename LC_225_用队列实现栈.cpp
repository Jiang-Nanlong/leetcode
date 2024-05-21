#include <iostream>
#include <queue>
using namespace std;

//用队列实现栈，也需要两个队列，其中一个队列用来备份另一个，比如说在pop时，就需要用备份队列B来备份另一个队列A的前n-1个元素，然后再弹出A的最后一个元素，然后再重新把备份队列B中的元素存到队列A中，这样就实现了后入先出的效果。

//class MyStack {
//public:
//	MyStack() {
//
//	}
//
//	void push(int x) {
//		que1.push(x);
//	}
//
//	int pop() {
//		int res;
//		if (!que1.empty()) {
//			int len = que1.size();
//			while (len-- != 1) {
//				que2.push(que1.front());
//				que1.pop();
//			}
//			res = que1.front();
//			que1.pop();
//		}
//		while (!que2.empty()) {
//			que1.push(que2.front());
//			que2.pop();
//		}
//		return res;
//	}
//
//	int top() {
//		/*int res = this->pop();    //这样也行，先弹出最后一个，然后再重新压入到队列A的队尾
//		que1.push(res);
//		return res;
//		*/
//		return que1.back();
//	}
//
//	bool empty() {
//		return que1.empty() && que2.empty();
//	}
//private:
//	queue<int> que1, que2;
//};

//只有pop的时候才用到两个队列，其实只用一个也行，只需要把出队的元素顺便插入到队尾就行，不过要弹出最后一个元素。
class MyStack {
public:
	MyStack() {

	}

	void push(int x) {
		que.push(x);
	}

	int pop() {
		int res;
		if (!que.empty()) {
			int len = que.size();
			while (len-- != 1) {
				que.push(que.front());
				que.pop();
			}
			res = que.front();
			que.pop();
		}

		return res;
	}

	int top() {
		/*int res = this->pop();    //这样也行，先弹出最后一个，然后再重新压入到队列A的队尾
		que1.push(res);
		return res;
		*/
		return que.back();
	}

	bool empty() {
		return que.empty();
	}
private:
	queue<int> que;
};

//第二次做，这个top()函数和之前写的一模一样
class MyStack1 {
public:
	MyStack1() {}

	void push(int x) { que.push(x); }

	int pop() {
		int size = que.size();
		while (size-- > 1) {
			int temp = que.front();
			que.pop();
			que.push(temp);
		}
		int res = que.front();
		que.pop();
		return res;
	}

	int top() {
		//int res = this->pop();
		//que.push(res);
		//return res;
		return que.back();
	}

	bool empty() { return que.empty(); }

private:
	queue<int> que;
};

// 第三次做
class MyStack2 {
public:
	MyStack2() {}

	void push(int x) { que.push(x); }

	int pop() {
		if (empty())
			return -1;
		int size = que.size();
		size -= 1;
		while (size--) {
			int num = que.front();
			que.pop();
			que.push(num);
		}
		int res = que.front();
		que.pop();
		return res;
	}

	int top() {
		int num = pop();
		que.push(num);
		return num;
	}

	bool empty() { return que.empty(); }

private:
	queue<int> que;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
	MyStack2 stk2;
	stk2.push(1);
	stk2.push(2);
	cout << stk2.top() << endl;
	cout << stk2.pop() << endl;
	cout << boolalpha << stk2.empty() << noboolalpha << endl;
	return 0;
}