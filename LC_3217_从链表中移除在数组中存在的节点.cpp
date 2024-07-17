#include <iostream>
#include <vector>
#include <unordered_set>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset(nums.begin(), nums.end());
        ListNode* phead = new ListNode(-1, head);
        ListNode* p = phead;
        while (p->next) {
            ListNode* temp = p->next;
            if (uset.find(temp->val) != uset.end()) {
                p->next = temp->next;
                delete temp;
            }
            else
                p = p->next;
        }
        return phead->next;
    }
};

int main() {
    Solution st;
    return 0;
}