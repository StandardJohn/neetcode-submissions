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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterHelper(root, 0, diameter);
        return diameter;
    }
    int diameterHelper(TreeNode* node, int depth, int& diameter) {
        if (!node) 
            return 0;
        int l = diameterHelper(node->left, depth + 1, diameter);
        int r = diameterHelper(node->right, depth + 1, diameter);
        // cout << node->val << " " << l << " " << r << " " << diameter << endl;
        diameter = max(diameter, l + r);
        return max(l + 1, r + 1);
    }
};