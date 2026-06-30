class Solution {
private:
    bool solve(TreeNode* root, int ts, int s) {

        if (!root)
            return false;

        s += root->val;

        if (!root->left && !root->right)
            return s == ts;

        return solve(root->left, ts, s) ||
               solve(root->right, ts, s);
    }

public:
    bool hasPathSum(TreeNode* root, int ts) {
        return solve(root, ts, 0);
    }
};