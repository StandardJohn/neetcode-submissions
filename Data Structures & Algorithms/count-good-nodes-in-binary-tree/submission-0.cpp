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

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        goodNodesHelper(root, -1e9, cnt);
        return cnt;
    }
    void goodNodesHelper(TreeNode* node, int maxVal, int& cnt) {
        if (!node)
            return;
        if (node->val >= maxVal)
            cnt++;
        maxVal = max(maxVal, node->val);
        goodNodesHelper(node->left, maxVal, cnt);
        goodNodesHelper(node->right, maxVal, cnt);
    }
};
