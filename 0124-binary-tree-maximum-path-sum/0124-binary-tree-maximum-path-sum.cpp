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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
private:
    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        ans = max(ans, max({root->val, root->val + l + r, root->val + l, root->val + r}));

        return max(root->val, root->val + max(l , r));
    }    
};