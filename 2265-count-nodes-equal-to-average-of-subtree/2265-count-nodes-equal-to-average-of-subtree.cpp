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
    int solve(TreeNode* root, int& cnt, int& n) {
        if (!root) {
            n = 0;
            return 0;
        }

        int leftN = 0;
        int left = solve(root->left, cnt, leftN);

        int rightN = 0;
        int right = solve(root->right, cnt, rightN);

        int currSum = left + right + root->val;
        n = leftN + rightN + 1;

        if (currSum / n == root->val)
            cnt++;

        return currSum;
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        int n = 0;

        solve(root, cnt, n);

        return cnt;
    }
};