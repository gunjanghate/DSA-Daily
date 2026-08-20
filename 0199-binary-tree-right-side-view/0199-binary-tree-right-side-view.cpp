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
    vector<int> rightSideView(TreeNode* root) {
        // code here
        queue<pair<TreeNode*, int>> q;
        if(root == nullptr) return {};
        q.push({root, 0});
        
        map<int, int> mpp;
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* t = p.first;
            int level = p.second;
            
            if(mpp.find(level)==mpp.end()) mpp[level] = t->val;
            if(t->right){
                q.push({t->right, level+1});
            }
            if(t->left){
                q.push({t->left, level+1});
            }
        }
        
        vector<int> ans;
        for(auto i : mpp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};