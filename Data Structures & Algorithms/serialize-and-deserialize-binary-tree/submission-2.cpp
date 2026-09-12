/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "null";
        }
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    TreeNode* buildTree(string& s, size_t& start) {
        if (s.empty())
            return nullptr;
        size_t comma = s.find(',', start);
        if (comma == string::npos) {
            comma = s.size();
        }
        string t = s.substr(start, comma - start);
        start = comma + 1;
        if (t == "null") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(t));
        node->left = buildTree(s, start);
        node->right = buildTree(s, start);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data << endl;
        size_t start = 0;
        return buildTree(data, start);
    }

    
};
