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
	ListNode* swapPairs(ListNode* head) {
		ListNode* preHead = new ListNode(-1);
		ListNode* cur = head, * pre = preHead;
		int count = 0;
		while (cur) {
			if (++count % 2 != 0) {
				pre->next = cur;
				cur = cur->next;
				pre->next->next = nullptr;
			}
			else {
				ListNode* temp = pre->next;
				pre->next = cur;
				cur = cur->next;
				pre->next->next = temp;
				pre = temp;
			}
		}
		return preHead->next;
	}

	//���ǵڶ���д�Ĵ��룬�����������ٿ���һ��д���Ѿ��������ˣ��о���ʱд���渴�ӣ����д�ļ򵥶��ˣ��ṹҲ������
	ListNode* swapPairs1(ListNode* head) {
		ListNode* phead = new ListNode(-1, head);
		ListNode* p = phead;
		while (p->next && p->next->next) {
			ListNode* temp = p->next;
			p->next = temp->next;
			temp->next = p->next->next;
			p->next->next = temp;
			p = p->next->next;
		}
		return phead->next;
	}

	//��������
	ListNode* swapPairs2(ListNode* head) {
		ListNode* phead = new ListNode(-1, head);
		ListNode* p = phead;
		while (p->next && p->next->next) {
			ListNode* temp1 = p->next;
			ListNode* temp2 = p->next->next;

			p->next = temp2;
			temp1->next = temp2->next;
			temp2->next = temp1;
			p = temp1;
		}
		return phead->next;
	}
};

int main() {

	return 0;
}