/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        unordered_map<Node*, int> pter_idx_map;
        unordered_map<int, Node*> idx_pter_map;
        Node* newNode = nullptr, *newHead = nullptr, *node = head;
        for (int i = 0; node; node = node->next, i++) {
            if (!newHead) {
                newNode = new Node(node->val);
                newHead = newNode;
            }
            else {
                newNode->next = new Node(node->val);
                newNode = newNode->next;
            }
            pter_idx_map.insert({node, i});
            idx_pter_map.insert({i, newNode});
        }
        // for (auto it = pter_idx_map.begin(); it != pter_idx_map.end(); ++it) {
        //     cout << it->first->val << " " << it->second << endl;
        // }
        // cout << newHead->next->val << endl;
        for (node = head, newNode = newHead; node; node = node->next, newNode = newNode->next) {
            if (node->random == nullptr) {
                newNode->random = nullptr;
                cout << node->val << " nullptr" << endl;
                continue;
            }
            // int j = pter_idx_map[node->random];
            // cout << newNode->val << " " << j << endl;
            // auto it = idx_pter_map.find(j);
            // it == idx_pter_map.end() ? cout << node->val << " nullptr" << endl : cout << node->val << " " << it->second->val << endl;
            // cout << pter_idx_map[node] << endl;
            newNode->random = idx_pter_map[pter_idx_map[node->random]];
        }
        return newHead;
    }
};