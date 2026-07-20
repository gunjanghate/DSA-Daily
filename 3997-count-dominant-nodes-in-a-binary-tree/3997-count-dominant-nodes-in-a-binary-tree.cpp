class Solution {
private:
    int ans = 0;

    int solve(TreeNode* root) {
        if (root == nullptr)
            return INT_MIN;

        int leftMax = solve(root->left);
        int rightMax = solve(root->right);

        int subtreeMax = max(root->val, max(leftMax, rightMax));

        if (root->val == subtreeMax)
            ans++;

        return subtreeMax;
    }

public:
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;
    }
};