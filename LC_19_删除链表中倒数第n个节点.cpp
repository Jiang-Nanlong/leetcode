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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* preHead = new ListNode(-1, head);  //为了防止删除的是链表中的第一个，所以加了一个头结点
		ListNode* fast = preHead, * slow = preHead;
		while (n--) {
			fast = fast->next;
		}
		while (fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* temp = slow->next;
		slow->next = temp->next;
		delete temp;
		temp = nullptr;
		return preHead->next;
	}

	//第二回做
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* phead = new ListNode(-1, head);
		ListNode* p = phead, * q = phead;
		while (n--)
			p = p->next;
		while (p->next) {
			p = p->next;
			q = q->next;
		}
		ListNode* temp = q->next;
		q->next = temp->next;
		delete temp;
		return phead->next;
	}
};

int main() {

	return 0;
}
