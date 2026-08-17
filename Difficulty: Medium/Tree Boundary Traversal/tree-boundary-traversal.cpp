/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:

    void addLeft(Node* root, vector<int>& res) {
        Node* curr = root->left;

        while (curr) {
  
            if (!(curr->left == nullptr && curr->right == nullptr)) {
                res.push_back(curr->data);
            }

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addRight(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!(curr->left == nullptr && curr->right == nullptr)) {
                temp.push_back(curr->data);
            }

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    void addLeaf(Node* root, vector<int>& res) {
        if (!root)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(root->data);
            return;
        }

        addLeaf(root->left, res);
        addLeaf(root->right, res);
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> res;

        if (!root)
            return res;

        if (!(root->left == nullptr && root->right == nullptr)) {
            res.push_back(root->data);
        }

        addLeft(root, res);
        addLeaf(root, res);
        addRight(root, res);

        return res;
    }
};