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
        if (!head) return nullptr;
        vector<int> nodes;
        while(head) {
            nodes.push_back(head->val);
            head = head->next;
        }
        ListNode *ans = new ListNode(nodes.back());
        ListNode *ansHead = ans;
        for (int i = nodes.size() - 2; i >= 0; i--) {
            ans->next = new ListNode(nodes[i]);
            ans = ans->next;
        }
        return ansHead;
    }
};
