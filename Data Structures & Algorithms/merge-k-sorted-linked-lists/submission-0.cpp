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
    struct c {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merge = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, c> pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* node = lists[i];
            while(node) {
                pq.push(node);
                node = node->next;
            }
        }
        ListNode* node = merge;
        while (!pq.empty()) {
            // cout << pq.top()->val << endl;
            if (!merge) {
                merge = pq.top();
                node = merge;
            }
            else {
                node->next = pq.top();
                node = node->next;
            }
            pq.pop();
        }
        return merge;
    }
};
