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
		ListNode *detectCycle(ListNode *head) {   //�������Լ�д�ģ�Ҳ��ʵ�֡�����һ��unordered_set�洢�����Ľڵ�ĵ�ַ��������ڻ���һ������unordered_set���ҵ��ظ��ĵ�ַ���ҵ�һ���ظ���ַ������ڡ���������Լ��˳�ѭ��˵��û�л���
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
	ListNode* detectCycle(ListNode* head) {    //����ǿ��Ĵ�������¼�ģ�˼·���������������ġ���ͨ������ָ���ж��ǲ����л�������л��ټ������뻷�ڵ㡣
		ListNode* fast = head, * slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {   //���ڻ�
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