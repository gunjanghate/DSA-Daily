/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:

    void markParent(Node* root, unordered_map<Node*, Node*>& parents) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->left) {
                parents[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    Node* findTarget(Node* root, int target) {
        if (!root)
            return nullptr;

        if (root->data == target)
            return root;

        Node* left = findTarget(root->left, target);
        if (left)
            return left;

        return findTarget(root->right, target);
    }

    int minTime(Node* root, int target) {

        unordered_map<Node*, Node*> parents;
        markParent(root, parents);

        Node* temp = findTarget(root, target);

        unordered_map<Node*, bool> vis;

        queue<Node*> q;
        q.push(temp);
        vis[temp] = true;

        int time = 0;

        while (!q.empty()) {

            int size = q.size();
            bool burned = false;

            while (size--) {

                Node* curr = q.front();
                q.pop();

                if (curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                    burned = true;
                }

                if (curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                    burned = true;
                }

                if (parents.count(curr) && !vis[parents[curr]]) {
                    vis[parents[curr]] = true;
                    q.push(parents[curr]);
                    burned = true;
                }
            }

            if (burned)
                time++;
        }

        return time;
    }
};