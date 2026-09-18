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
    unordered_map<Node*, Node*> indexNodeMap;

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        auto it = indexNodeMap.find(node);
        Node* newNode = nullptr;
        if (it == indexNodeMap.end()) {
            newNode = new Node(node->val);
            indexNodeMap.insert({node, newNode});
        }
        else {
            newNode = it->second;
            return newNode;
        }
        for (int i = 0; i < node->neighbors.size(); i++) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    }
};
