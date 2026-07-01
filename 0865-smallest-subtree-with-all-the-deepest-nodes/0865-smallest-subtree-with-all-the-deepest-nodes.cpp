/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }

    TreeNode* solve(TreeNode* root, int d, int md) {
        if (!root)
            return nullptr;

        if (d == md)
            return root;

        TreeNode* left = solve(root->left, d + 1, md);
        TreeNode* right = solve(root->right, d + 1, md);

        if (left && right)
            return root;

        return left ? left : right;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int md = maxDepth(root) - 1;

        return solve(root, 0, md);
    }
};