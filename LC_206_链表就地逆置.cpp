#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* preHead = new ListNode(-1); //创建一个临时头结点，使用头插法插入后续节点。	
		ListNode* ptr = head;
		while (ptr) {
			ListNode* temp = preHead->next;
			preHead->next = ptr;
			ptr = ptr->next;
			preHead->next->next = temp;
		}
		return preHead->next;
	}

	//第二次做，还是弄个头结点，然后头插法就地逆置
	ListNode* reverseList1(ListNode* head) {
		ListNode* phead = new ListNode(-1);
		ListNode* p = head;
		while (p) {
			ListNode* temp = p;
			p = p->next;
			temp->next = phead->next;
			phead->next = temp;
			temp = nullptr;
		}
		head = phead->next;
		delete phead;
		return head;
	}
};

int main() {
	return 0;
}
