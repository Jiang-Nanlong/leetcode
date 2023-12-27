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
	MyLinkedList mlist;
	return 0;
}