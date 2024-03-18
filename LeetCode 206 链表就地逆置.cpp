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
		ListNode* preHead = new ListNode(-1); //����һ����ʱͷ��㣬ʹ��ͷ�巨��������ڵ㡣	
		ListNode* ptr = head;
		while (ptr) {
			ListNode* temp = preHead->next;
			preHead->next = ptr;
			ptr = ptr->next;
			preHead->next->next = temp;
		}
		return preHead->next;
	}

	//�ڶ�����������Ū��ͷ��㣬Ȼ��ͷ�巨�͵�����
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