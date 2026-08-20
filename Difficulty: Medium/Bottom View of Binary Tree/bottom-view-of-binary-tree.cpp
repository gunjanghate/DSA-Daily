/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        // code here
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        map<int, int> mpp;

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* t = p.first;
            int level = p.second;

            mpp[level] = t->data;
            if(t->left){
                q.push({t->left, level-1});
            }
            if(t->right){
                q.push({t->right, level+1});
            }
        }

        vector<int> ans;
        for(auto i : mpp){
            ans.push_back(i.second);
        }

        return ans;
    }
};