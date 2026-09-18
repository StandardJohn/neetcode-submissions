/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, unordered_set<int>> umap;
    unordered_map<int, Node*> indexNodeMap;

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        auto it = indexNodeMap.find(node->val);
        Node* newNode = nullptr;
        if (it == indexNodeMap.end()) {
            newNode = new Node(node->val);
            indexNodeMap.insert({node->val, newNode});
        }
        else {
            newNode = it->second;
        }
        for (int i = 0; i < node->neighbors.size(); i++) {
            auto it1 = umap.find(node->val);
            if (it1 != umap.end()) {
                auto it2 = it1->second.find(node->neighbors[i]->val);
                if (it2 != it1->second.end()) {
                    // cout << node->val << " skip " << node->neighbors[i]->val << endl;
                    continue;
                }
            }
            // cout << node->val << " " << node->neighbors[i]->val << endl;
            umap[node->val].insert(node->neighbors[i]->val);
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    }
};
