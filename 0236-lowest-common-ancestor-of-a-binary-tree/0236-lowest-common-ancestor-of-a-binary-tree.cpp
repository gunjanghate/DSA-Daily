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

        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else { 
            return root;
        }
    }
};