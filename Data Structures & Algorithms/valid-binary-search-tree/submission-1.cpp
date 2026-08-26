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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
    bool isValidBSTHelper(TreeNode* node, int lowerbound, int upperbound) {
        if (!node)
            return true;
        if (node->val <= lowerbound || node->val >= upperbound) 
            return false;
        return isValidBSTHelper(node->left, lowerbound, node->val) && isValidBSTHelper(node->right, node->val, upperbound);
    }
};
