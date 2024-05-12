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

	//这是第二次写的代码，但是我现在再看第一次写的已经看不懂了，感觉当时写的真复杂，这会写的简单多了，结构也清晰。
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

	//第三次做
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