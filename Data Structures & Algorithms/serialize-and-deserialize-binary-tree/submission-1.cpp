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

    TreeNode* buildTree(queue<string>& q, TreeNode* node) {
        if (q.empty())
            return nullptr;

        string s = q.front();
        q.pop();
        // cout << s << endl;
        if (s == "null") {
            return nullptr;
        }
        node = new TreeNode(stoi(s));
        node->left = buildTree(q, node->left);
        node->right = buildTree(q, node->right);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        queue<string> q;
        size_t start = 0;
        size_t comma = data.find(',');
        while (comma != string::npos) {
            string token = data.substr(start, comma - start);
            q.push(token);
            start = comma + 1;
            comma = data.find(',', start);
        }
        q.push(data.substr(start));
        return buildTree(q, nullptr);
    }

    
};
