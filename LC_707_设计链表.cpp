#include <iostream>
using namespace std;

class MyLinkedList {
public:
	struct ListedNode {
		int val;
		ListedNode* next;
		ListedNode() :val(0), next(nullptr) {}
		ListedNode(int x) :val(x), next(nullptr) {}
		ListedNode(int x, ListedNode* p) :val(x), next(p) {}
	};
	MyLinkedList() {
		ListHead = new ListedNode();  //定义一个头结点
		sizeofList = 0;
	}

	int get(int index) {
		if (index > (sizeofList - 1) || index < 0) return -1;
		ListedNode* temp = ListHead->next;
		while (index--) {
			temp = temp->next;
		}
		return temp->val;
	}

	void addAtHead(int val) {
		ListedNode* temp = new ListedNode(val, ListHead->next);
		ListHead->next = temp;
		sizeofList++;
	}

	void addAtTail(int val) {
		ListedNode* ptr = ListHead;
		while (ptr->next) {
			ptr = ptr->next;
		}
		ListedNode* temp = new ListedNode(val);
		ptr->next = temp;
		sizeofList++;
	}

	void addAtIndex(int index, int val) {
		if (index > sizeofList) return;
		ListedNode* ptr = ListHead;
		while (index--) {
			ptr = ptr->next;
		}
		ListedNode* temp = new ListedNode(val, ptr->next);
		ptr->next = temp;
		sizeofList++;
	}

	void deleteAtIndex(int index) {
		if (index >= sizeofList || index < 0) return;
		ListedNode* ptr = ListHead;
		while (index--) {
			ptr = ptr->next;
		}
		ListedNode* temp = ptr->next;
		ptr->next = ptr->next->next;
		delete temp;
		temp = nullptr;
		sizeofList--;
	}
private:
	ListedNode* ListHead;
	int sizeofList;
};

//下边是第二遍做
class MyLinkedList1 {
public:
	struct ListedNode {
		ListedNode* next;
		int val;
		ListedNode() : next(nullptr), val(0) {}
		ListedNode(int x) : next(nullptr), val(x) {}
		ListedNode(int x, ListedNode* p) : next(p), val(x) {}
	};

	MyLinkedList1() {
		NodeList = new ListedNode(-1);
		nodeNum = 0;
	}

	int get(int index) {
		if (index >= nodeNum || index < 0)
			return -1;
		ListedNode* p = NodeList->next;   //注意这里的index是从NodeList->next开始算的，但是下边的addAtIndex和deleteAtIndex都是从NodeList开始算的，因为这里的get最后就是要让指针指向index处，而另外两个都是要指向index的前一个
		for (int i = 0; i < index; i++)   //这里循环index次，指向index，从第0个元素开始，移动一下，指向第一个元素；移动两下，指向第二个元素，以此类推
			p = p->next;
		return p->val;
	}

	void addAtHead(int val) {
		ListedNode* temp = new ListedNode(val, NodeList->next);
		NodeList->next = temp;
		nodeNum++;
	}

	void addAtTail(int val) {
		ListedNode* newtail = new ListedNode(val);
		ListedNode* p = NodeList;
		while (p->next)
			p = p->next;
		p->next = newtail;
		nodeNum++;
	}

	void addAtIndex(int index, int val) {
		if (index > nodeNum || index < 0) return;
		ListedNode* p = NodeList;
		for (int i = 0; i < index; i++)
			p = p->next;
		ListedNode* newNode = new ListedNode(val, p->next);
		p->next = newNode;
		nodeNum++;
	}

	void deleteAtIndex(int index) {
		if (index >= nodeNum || index < 0) return;
		ListedNode* p = NodeList;
		for (int i = 0; i < index; i++)
			p = p->next;
		ListedNode* temp = p->next;
		p->next = temp->next;
		delete temp;
		nodeNum--;
	}

private:
	ListedNode* NodeList;
	int nodeNum;
};


// 第三次做
class MyLinkedList2 {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	MyLinkedList2() {
		phead = new ListNode(-1);
		num = 0;
	}

	int get(int index) {
		if (index >= num) return -1;
		ListNode* p = phead->next;
		while (index--) {
			p = p->next;
		}
		return p->val;
	}

	void addAtHead(int val) {
		ListNode* newNode = new ListNode(val, phead->next);
		phead->next = newNode;
		num++;
	}

	void addAtTail(int val) {
		ListNode* p = phead;
		while (p->next) {
			p = p->next;
		}
		ListNode* newNode = new ListNode(val);
		p->next = newNode;
		num++;
	}

	void addAtIndex(int index, int val) {
		if (index > num) return;
		ListNode* p = phead;
		while (index--)
			p = p->next;

		ListNode* newNode = new ListNode(val, p->next);
		p->next = newNode;
		num++;
	}

	void deleteAtIndex(int index) {
		if (index >= num) return;
		ListNode* p = phead;
		while (index--)
			p = p->next;
		ListNode* temp = p->next;
		p->next = temp->next;
		delete temp;
		num--;
	}

private:
	ListNode* phead;
	int num;

};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
	MyLinkedList2 mlist;
	mlist.addAtHead(1);
	mlist.addAtTail(3);
	mlist.addAtIndex(1, 2);
	cout << mlist.get(1) << endl;
	mlist.deleteAtIndex(1);
	cout << mlist.get(1) << endl;
	return 0;
}

