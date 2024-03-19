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
};

int main() {
	return 0;
}