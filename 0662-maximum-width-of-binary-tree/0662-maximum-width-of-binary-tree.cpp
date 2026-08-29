class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (!root)
            return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();

            long long minn = q.front().second;

            long long first = 0;
            long long last = 0;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                long long id = q.front().second;

                q.pop();

                long long cur_id = id - minn;

                if (i == 0)
                    first = cur_id;

                if (i == size - 1)
                    last = cur_id;

                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});

                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};