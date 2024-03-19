#include <iostream>
using namespace std;

/*
* �����������ж����������ǲ������ཻ�ĵ㣬����з����ཻ�ĵ�ĵ�ַ�����û�У�����null��
* �����Ƚϼ򵥣��ȷֱ������������ĳ��ȣ��Ӻ���ǰ��������н��㣬�ǿ϶��ڶ̵���һ����ߡ�Ȼ��������ָ��ֱ�ָ�����������ͷ��㣬Ȼ�󳤵��Ǹ���ָ����뵽�̵��Ǹ���
* Ȼ��ʼ�������������ȵĵ�ַ����ô���ǵ�һ���ཻ�Ľڵ㡣��������û�У��Ǿ���û�С�
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


	//���ǵڶ���д�Ĵ��룬�����һ������ʱ��д�ļ�࣬���ǵ�һ��д�ıȽϺ�
	ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
		int countA = 0, countB = 0;
		ListNode* pheadA = new ListNode(-1), * pheadB = new ListNode(-1);
		pheadA->next = headA, pheadB->next = headB;
		ListNode* pA = pheadA, * pB = pheadB;
		while (pA->next) {
			countA++;
			pA = pA->next;
		}
		while (pB->next) {
			countB++;
			pB = pB->next;
		}

		cout << countA << "  " << countB;
		if (countA < countB) {  //������pAʼ��ָ�������һ���������ֻ��Ҫ��ǰ�ƶ�pA����
			pA = pheadB;
			pB = pheadA;
		}
		else {
			pA = pheadA;
			pB = pheadB;
		}

		for (int i = 0; i < abs(countA - countB); i++) {
			pA = pA->next;
		}
		while (pA && pA->next) {
			if (pA->next == pB->next)
				return pA->next;
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