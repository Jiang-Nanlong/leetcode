//
// Created by ²ÜÃÏÁú on 25-4-3.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
private:
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *phead = new ListNode(0);
        ListNode *p = phead;
        while (left && right) {
            if (left->val <= right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if (left)
            p->next = left;
        if (right)
            p->next = right;
        return phead->next;
    }

    ListNode *getmid(ListNode *list) {
        ListNode *pre = list;
        ListNode *slow = list, *fast = list;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return slow;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *left = head;
        ListNode *right = getmid(head);
        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};

int main() {
    Solution st;
    ListNode *p = nullptr;
    ListNode *head = new ListNode(4);
    p = new ListNode(2);
    head->next = p;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(3);

    p = st.sortList(head);
    while (p) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
