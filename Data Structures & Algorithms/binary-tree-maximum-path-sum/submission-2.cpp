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
    int max_sum = -1e9;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left = max(0, dfs(node->left)),
            right = max(0, dfs(node->right));
        max_sum = max(max_sum, max(left + right + node->val, max(left + node->val, right + node->val)));
        return max(node->val, max(left + node->val, right + node->val));
    }
};