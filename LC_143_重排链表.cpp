#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution() {
        phead = new ListNode(-1);
        tail = phead;
    }

    void addNodeToList(vector<int>& vec) {
        for (auto& i : vec) {
            ListNode* newNode = new ListNode(i);
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void reorderList() {
        ListNode* slow = phead->next, * fast = phead->next, * pre = phead->next;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;

        ListNode* qhead = new ListNode(-1);   // 翻转后半段链表
        while (slow) {
            ListNode* temp = slow;
            slow = slow->next;
            temp->next = qhead->next;
            qhead->next = temp;
        }
        /*
        slow=qhead->next;
        while(slow){
            cout<<slow->val<<" ";
            slow=slow->next;
        }
        */
        ListNode* p = phead->next, * q = qhead->next;
        if (p == q) //如果整个链表只有一个节点，直接返回
            return;
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while (p) {
            cur->next = p;
            p = p->next;
            cur = cur->next;
            cur->next = q;
            q = q->next;
            cur = cur->next;
        }
        phead->next = head->next;
    }

    void printList() {
        ListNode* p = phead->next;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
    }

private:
    ListNode* phead;
    ListNode* tail;  //指向最后一个节点
};

int main() {
    Solution st;
    vector<int> vec{ 1,2,3,4,5 };
    st.addNodeToList(vec);
    st.reorderList();
    st.printList();
    return 0;
}