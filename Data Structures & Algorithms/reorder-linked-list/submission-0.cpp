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
    void reorderList(ListNode* head) {
        if (!head)
            return;
        stack<ListNode*> s;
        ListNode* i = head, *j = head;
        while (j) {
            s.push(j);
            j = j->next;
        }
        j = s.top();

        while(i != j && i->next != j) {
            // cout << i->val << " " << j->val << endl;
            j->next = i->next;
            i->next = j;
            i = j->next;
            s.pop();
            j = s.top();
        }
        if (i == j)
            i->next = nullptr;
        else
            j->next = nullptr;
    }
};