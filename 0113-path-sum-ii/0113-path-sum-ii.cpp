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
private:
    void solve(TreeNode* root, int ts, int s, vector<vector<int>> & ans, vector<int> arr) {

        if (!root)
            return;

        s += root->val;
        arr.push_back(root->val);

        // Check only at a leaf
        if (!root->left && !root->right)
            {
                if(s==ts) ans.push_back(arr);
                else arr.pop_back();
                return;
            }

        solve(root->left, ts, s, ans, arr);
        solve(root->right, ts, s, ans, arr);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(root, ts, 0, ans, arr);
        return ans;
    }
};