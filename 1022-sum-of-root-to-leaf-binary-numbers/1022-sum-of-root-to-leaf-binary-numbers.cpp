class Solution {
public:

    void solve(TreeNode* root, string path, vector<string>& paths) {
        
        if (root == NULL) return;

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path);
            return;
        }

        // Go left
        solve(root->left, path, paths);

        // Go right
        solve(root->right, path, paths);
    }

    int sumRootToLeaf(TreeNode* root) {

        vector<string> paths;

        solve(root, "", paths);

        int totalSum = 0;

        for (string s : paths) {
            int decimalValue = 0;

            for (char c : s) {
                decimalValue = decimalValue * 2 + (c - '0');
            }

            totalSum += decimalValue;
        }

        return totalSum;
    }
};