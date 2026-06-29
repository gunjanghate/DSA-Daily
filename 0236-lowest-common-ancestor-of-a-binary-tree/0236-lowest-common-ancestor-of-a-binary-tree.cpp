class Solution {
public:
    int solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
        if (root == nullptr)
            return 0;

        int left = solve(root->left, p, q, ans);
        int right = solve(root->right, p, q, ans);

        int self = (root == p || root == q);

        int total = left + right + self;

        if (total == 2 && ans == nullptr)
            ans = root;

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans = nullptr;

        solve(root, p, q, ans);

        return ans;
    }
};