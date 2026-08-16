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
        int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return res;
    }

private:
    int diameter(TreeNode* curr){
        if (!curr) return 0;
        
        int left = diameter(curr->left);
        int right = diameter(curr->right);
        res = max(res, left + right);
        
        return max(left, right) + 1;
    }
};