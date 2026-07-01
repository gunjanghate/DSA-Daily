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
public:
    int dfs(TreeNode* root, long long sum, int target) {
        if (!root)
            return 0;

        sum += root->val;

        int cnt = (sum == target);

        cnt += dfs(root->left, sum, target);
        cnt += dfs(root->right, sum, target);

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        return dfs(root, 0, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};