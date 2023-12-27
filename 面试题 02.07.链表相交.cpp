#include <iostream>
using namespace std;

/*
* 有两个链表，判断两个链表是不是有相交的点，如果有返回相交的点的地址，如果没有，返回null。
* 这个题比较简单，先分别算出两个链表的长度，从后往前看，如果有交点，那肯定在短的那一根里边。然后用两个指针分别指向两个链表的头结点，然后长的那根的指针对齐到短的那根。
* 然后开始遍历，如果有相等的地址，那么就是第一个相交的节点。如果到最后都没有，那就是没有。
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		int countA = 0, countB = 0;
		ListNode* preA = headA, * preB = headB;
		while (preA) {
			++countA;
			preA = preA->next;
		}
		while (preB) {
			++countB;
			preB = preB->next;
		}
		preA = headA;
		preB = headB;
		if (countA > countB) {
			int difference = countA - countB;
			while (difference--) preA = preA->next;
		}
		else {
			int difference = countB - countA;
			while (difference--) preB = preB->next;
		}
		while (preA) {
			if (preA == preB) return preA;
			else {
				preA = preA->next;
				preB = preB->next;
			}
		}
		return NULL;
	}
};

int main() {

	return 0;
}