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
    bool hasCycle(ListNode* head) {
        if (!head) 
            return false;
        unordered_set<ListNode*> uset;
        ListNode* node = head;
        while (node) {
            if (uset.find(node) != uset.end()) {
                return true;
            }
            uset.insert(node);
            node = node->next;
        }
        return false;
    }
};
