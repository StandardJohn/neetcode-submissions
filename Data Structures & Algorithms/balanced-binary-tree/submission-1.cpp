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
    bool isBalanced(TreeNode* root) {
        if (!root) 
            return true;
        // cout << maxHeight(root->left) << " " << maxHeight(root->right) << endl;
        return isBalanced(root->left) && isBalanced(root->right) && abs(maxHeight(root->left) - maxHeight(root->right)) <= 1;
    }
    int maxHeight(TreeNode* node) {
        if (!node)
            return 0;
        return max(maxHeight(node->left), maxHeight(node->right)) + 1;
    }
};