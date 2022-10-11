#include <iostream>
using namespace Solution::ListNode;
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* removeNthFromEnd(Solution::ListNode* head, int n) {
        ListNode* Ptr1 = head, * Ptr2 = head, * temp = nullptr;
        for (int i = 0; i < n && Ptr2->next != nullptr; i++)
            Ptr2 = Ptr2->next;
        if (Ptr2->next == nullptr) return head->next;
        while (Ptr2->next != nullptr) {
            Ptr1 = Ptr1->next;
            Ptr2 = Ptr2->next;
        }
        temp = Ptr1->next;
        Ptr1 = temp->next;
        free(temp);
        return head;

    }
private:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
};