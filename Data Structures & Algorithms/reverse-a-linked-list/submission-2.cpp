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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* node = head;
        while (node->next) {
            node = node->next;
        }
        r(head, nullptr);
        return node;
    }

    void r(ListNode* node, ListNode* prev) {
        if (node->next == nullptr) {
            node->next = prev;
            return;
        }
        r(node->next, node);
        node->next = prev;
    }
};
