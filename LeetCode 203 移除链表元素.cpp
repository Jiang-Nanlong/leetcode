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
};

