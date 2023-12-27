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
};

int main() {
	return 0;
}