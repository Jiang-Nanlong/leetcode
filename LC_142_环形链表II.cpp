#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*
		ListNode *detectCycle(ListNode *head) {   //这是我自己写的，也能实现。用了一个unordered_set存储经过的节点的地址。如果存在环，一定能在unordered_set中找到重复的地址，且第一个重复地址就是入口。如果链表自己退出循环说明没有环。
			unordered_set<ListNode*> address;
			ListNode* ptr = head;
			while(ptr){
				auto it = address.find(ptr);
				if(it!=address.end())
					return ptr;
				else
					address.insert(ptr);
				ptr = ptr->next;
			}
			return NULL;
		}
	*/

	//第二次再看，我头一回做居然能想到用unordered_set，我现在都想不到。
	//这里可以把快慢指针每次移动一格和两格看成速度，然后从开始到相遇经过的时间相同，所以快指针走过的路程是慢指针走过路程的2倍。2*(x+y)=x+y+n(y+z)
	ListNode* detectCycle(ListNode* head) {    //这个是看的代码随想录的，思路很巧妙，计算算出来的。先通过快慢指针判断是不是有环，如果有环再继续找入环节点。
		ListNode* fast = head, * slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {   //存在环
				ListNode* index1 = fast, * index2 = head;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index1;
			}
		}
		return NULL;
	}
};

int main() {

	return 0;
}
