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
		ListHead = new ListedNode();  //����һ��ͷ���
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

//�±��ǵڶ�����
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
		ListedNode* p = NodeList->next;   //ע�������index�Ǵ�NodeList->next��ʼ��ģ������±ߵ�addAtIndex��deleteAtIndex���Ǵ�NodeList��ʼ��ģ���Ϊ�����get������Ҫ��ָ��ָ��index������������������Ҫָ��index��ǰһ��
		for (int i = 0; i < index; i++)   //����ѭ��index�Σ�ָ��index���ӵ�0��Ԫ�ؿ�ʼ���ƶ�һ�£�ָ���һ��Ԫ�أ��ƶ����£�ָ��ڶ���Ԫ�أ��Դ�����
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

