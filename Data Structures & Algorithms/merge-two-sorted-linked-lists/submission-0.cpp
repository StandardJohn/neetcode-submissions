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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l = nullptr;
        while (list1 || list2) {
            if (!list1) {
                l = append(l, list2->val);
                list2 = list2->next;
            }
            else if (!list2) {
                l = append(l, list1->val);
                list1 = list1->next;
            }
            else if (list1->val < list2->val){
                l = append(l, list1->val);
                list1 = list1->next;
            }
            else {
                l = append(l, list2->val);
                list2 = list2->next;
            }
        }
        return l;
    }
    ListNode* append(ListNode* l, int v) {
        if (!l) {
            return new ListNode(v);
        }
        ListNode* t = l;
        while(t->next)
            t = t->next;
        t->next = new ListNode(v);
        return l;
    }
};
