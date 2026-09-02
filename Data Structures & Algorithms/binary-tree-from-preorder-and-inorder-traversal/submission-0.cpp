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
    unordered_map<int, int> umap;
    int i = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            umap.insert({inorder[i], i});
        }
        return buildTreeHelper(preorder, inorder, 0, n - 1);
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l > r)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[i]);
        int index = umap[preorder[i]];
        i++;
        node->left = buildTreeHelper(preorder, inorder, l, index - 1);
        node->right = buildTreeHelper(preorder, inorder, index + 1, r);
        return node;
    }
};
