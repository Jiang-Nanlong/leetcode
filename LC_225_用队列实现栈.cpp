#include <iostream>
#include <queue>
using namespace std;

//�ö���ʵ��ջ��Ҳ��Ҫ�������У�����һ����������������һ��������˵��popʱ������Ҫ�ñ��ݶ���B��������һ������A��ǰn-1��Ԫ�أ�Ȼ���ٵ���A�����һ��Ԫ�أ�Ȼ�������°ѱ��ݶ���B�е�Ԫ�ش浽����A�У�������ʵ���˺����ȳ���Ч����

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
//		/*int res = this->pop();    //����Ҳ�У��ȵ������һ����Ȼ��������ѹ�뵽����A�Ķ�β
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

//ֻ��pop��ʱ����õ��������У���ʵֻ��һ��Ҳ�У�ֻ��Ҫ�ѳ��ӵ�Ԫ��˳����뵽��β���У�����Ҫ�������һ��Ԫ�ء�
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
		/*int res = this->pop();    //����Ҳ�У��ȵ������һ����Ȼ��������ѹ�뵽����A�Ķ�β
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

//�ڶ����������top()������֮ǰд��һģһ��
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

// ��������
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