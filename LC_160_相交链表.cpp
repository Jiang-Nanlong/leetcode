#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		int countA = 0, countB = 0;
		ListNode* pA = headA, * pB = headB;
		while (pA) {
			countA++;
			pA = pA->next;
		}
		while (pB) {
			countB++;
			pB = pB->next;
		}

		if (countA < countB) {
			pA = headB;
			pB = headA;
		}
		else {
			pA = headA;
			pB = headB;
		}

		for (int i = 0; i < abs(countA - countB); i++) {
			pA = pA->next;
		}
		while (pA) {
			if (pA == pB)
				return pA;
			else {
				pA = pA->next;
				pB = pB->next;
			}
		}
		return NULL;
	}

	//第二次做
	ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
		int countA = 0, countB = 0;
		ListNode* p = headA, * q = headB;
		while (p) {
			countA++;
			p = p->next;
		}
		p = headA;
		while (q) {
			countB++;
			q = q->next;
		}
		q = headB;

		if (countA < countB) {
			p = headB;
			q = headA;
		}

		int diff = abs(countA - countB);
		while (diff--) {
			p = p->next;
		}

		while (p) {
			if (p == q)
				return p;
			p = p->next;
			q = q->next;
		}
		return nullptr;
	}
};

int main() {
	return 0;
}