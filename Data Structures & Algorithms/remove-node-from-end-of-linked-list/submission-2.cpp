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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next)
            return nullptr;
        ListNode* node = head, *prev = nullptr;
        int i = 0, size = 0;
        while(node) {
            size++;
            node = node->next;
        }
        node = head;
        while (i < size - n) {
            i++;
            prev = node;
            node = node->next;
        }
        if (!prev)
            head = head->next;
        else 
            prev->next = node->next;
        // cout << prev->val << " " << node->val << endl;
        return head;
    }
};
