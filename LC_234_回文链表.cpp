#include <iostream>
using namespace std;

// 判断一个链表是否是回文的

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    // 这是我写的代码，先计算出一共有多少个节点，然后另起一个链表，新链表是翻转以后的前一半链表，然后用新链表和后一半链表进行比较
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

        if (count % 2 == 1) {   // 如果节点个数为奇数，后一半链表的会比前一半多一个节点，所以去掉这个多余节点
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

    // 代码随想录的方法，他是用快慢指针来找到中间节点，然后另起新链表是翻转后一段链表。
    // 这时候后一半链表还是可能会比前一半多一个，但是翻转后就放到新链表最后了。然后只需要按着前一半链表的长度去比较即可。
    bool isPalindrome1(ListNode* head) {
        ListNode* slow = head, * fast = head, * pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;  //分割前半段链表

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