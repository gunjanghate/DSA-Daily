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
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int ans = INT_MIN;
        int sum = 0;
        int res = 0;

        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        while (!q.empty()) {
            int lsize = q.size();
            for (int i = 0; i < lsize; i++) {
                TreeNode* q1 = q.front();
                q.pop();
                sum += q1->val;

                if (q1->left)
                    q.push(q1->left);
                if (q1->right)
                    q.push(q1->right);
            }
            if(sum > ans){
                ans = sum;
                res = l;
            }

            l++;
            sum = 0;
        }


        return res;
    }
};