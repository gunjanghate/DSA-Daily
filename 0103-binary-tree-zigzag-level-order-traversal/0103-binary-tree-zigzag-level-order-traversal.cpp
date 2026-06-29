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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool alt = false;
        while (!q.empty()) {
            int s = q.size();
            vector<int> temp(s);

            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();

                int idx = alt ? (s - 1 - i) : i;
                temp[idx] = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(temp);
            alt = !alt;
        }

        return ans;
    }
};