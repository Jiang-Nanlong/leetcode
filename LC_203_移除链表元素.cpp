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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* h = new ListNode(-1, head);
		ListNode* ptr = h, * temp = nullptr;
		while (ptr->next) {
			if (ptr->next->val == val) {
				temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
			}
			else {
				ptr = ptr->next;
			}
		}
		return h->next;
	}

	//第二回写的代码
	ListNode* removeElements1(ListNode* head, int val) {
		if (head == nullptr)
			return nullptr;
		ListNode* phead = new ListNode(-1);
		phead->next = head;
		ListNode* p = phead;
		while (p->next) {
			if (p->next->val == val) {
				ListNode* temp = p->next;
				p->next = temp->next;
				temp->next = nullptr;
				delete temp;
			}
			else
				p = p->next;   //开始的时候这里的逻辑写错了，没有写else，一直报超时的错误，后来手动演示了一遍才知道
		}
		return phead->next;
	}
};

