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
};

int main() {

	return 0;
}