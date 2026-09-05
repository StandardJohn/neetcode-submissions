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
    ListNode* h = nullptr;
    ListNode* reverseList(ListNode* head) {
       r(head, nullptr);
       return h;
    }

    void r(ListNode* curr, ListNode* prev) {
        if (!curr) {
            h = prev;
            return;
        }
        r(curr->next, curr);
        curr->next = prev;
    }
};
