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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        ListNode *dummy = nullptr, *groupPrev = dummy;
        while (1) {
            ListNode* groupTail = getGroupTail(groupPrev, k, head);
            // cout << groupTail->val << endl;
            if (!groupTail)
                break;
            ListNode* groupNext = groupTail->next, *prev = groupNext, *curr = !groupPrev ? head : groupPrev->next;
            while(curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if (groupPrev) {
                ListNode* temp = groupPrev->next;
                groupPrev->next = groupTail;
                groupPrev = temp;
            }
            else {
                dummy = groupTail;
                groupPrev = head;
            }
        }
        return dummy;
    }
    
    ListNode* getGroupTail(ListNode* curr, int k, ListNode* head) {
        if (!curr) {
            curr = head;
            k--;
        }
        while(curr && k--) {
            curr = curr->next;
        }
        return curr;
    }
};
