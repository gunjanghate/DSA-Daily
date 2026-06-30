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
// class Solution {
// private:
//     void solve(TreeNode* root, vector<string>& ans, string arr) {

//         if (!root)
//             return;

//         arr.push_back(root->val + '0');

//         if (!root->left && !root->right) {
//             ans.push_back(arr);
//             return;
//         }

//         solve(root->left, ans, arr);
//         solve(root->right, ans, arr);
//     }

//     vector<string> pathSum(TreeNode* root) {
//         vector<string> ans;
//         string arr = "";

//         solve(root, ans, arr);

//         return ans;
//     }

// public:
//     int sumNumbers(TreeNode* root) {

//         vector<string> sums = pathSum(root);

//         int total = 0;

//         for (string s : sums) {
//             total += stoi(s);
//         }

//         return total;
//     }
// };

class Solution {
public:
    int solve(TreeNode* root, int num) {

        if (!root)
            return 0;

        num = num * 10 + root->val;

        if (!root->left && !root->right)
            return num;

        return solve(root->left, num) +
               solve(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};