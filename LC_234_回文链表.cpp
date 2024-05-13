#include <iostream>
using namespace std;

// �ж�һ�������Ƿ��ǻ��ĵ�

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    // ������д�Ĵ��룬�ȼ����һ���ж��ٸ��ڵ㣬Ȼ������һ�������������Ƿ�ת�Ժ��ǰһ������Ȼ����������ͺ�һ��������бȽ�
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* phead = new ListNode(-1, head);
        ListNode* p = phead;
        while (p->next) {
            count++;
            p = p->next;
        }

        if (count == 0 || count == 1)
            return true;

        int index = count / 2;
        ListNode* qhead = new ListNode(-1);
        p = phead->next;
        while (index--) {
            ListNode* temp = p;
            p = p->next;
            phead->next = p;
            temp->next = qhead->next;
            qhead->next = temp;
        }

        if (count % 2 == 1) {   // ����ڵ����Ϊ��������һ������Ļ��ǰһ���һ���ڵ㣬����ȥ���������ڵ�
            phead->next = p->next;
            p = phead->next;
        }

        ListNode* q = qhead->next;
        while (p) {
            if (p->val == q->val) {
                p = p->next;
                q = q->next;
            }
            else
                return false;
        }
        return true;
    }

    // ��������¼�ķ����������ÿ���ָ�����ҵ��м�ڵ㣬Ȼ�������������Ƿ�ת��һ������
    // ��ʱ���һ�������ǿ��ܻ��ǰһ���һ�������Ƿ�ת��ͷŵ�����������ˡ�Ȼ��ֻ��Ҫ����ǰһ������ĳ���ȥ�Ƚϼ��ɡ�
    bool isPalindrome1(ListNode* head) {
        ListNode* slow = head, * fast = head, * pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;  //�ָ�ǰ�������

        ListNode* qhead = new ListNode(-1);
        while (slow) {
            ListNode* temp = slow;
            slow = slow->next;
            temp->next = qhead->next;
            qhead->next = temp;
        }

        ListNode* p = head;
        ListNode* q = qhead->next;
        while (p) {
            if (p->val == q->val) {
                p = p->next;
                q = q->next;
            }
            else
                return false;
        }
        return true;
    }
};

int main() {

    return 0;
}