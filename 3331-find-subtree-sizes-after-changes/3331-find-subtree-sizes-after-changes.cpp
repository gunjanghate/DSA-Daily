class Solution {
public:

    unordered_map<int, vector<int>> adj;
    vector<int> resSize;
    vector<int> lastAnces;

    void dfs(int node, string &s, vector<int>& parent){

        int c = s[node]  - 'a';
        int nearAnces = lastAnces[c];

        lastAnces[c] = node;
        for(auto child : adj[node]){
            dfs(child, s, parent);
        }

        lastAnces[c] = nearAnces;
        if(node !=0){
            int newP = parent[node];
            if(nearAnces!=-1) 
                newP = nearAnces;
            parent[node] = newP;

            resSize[newP] += resSize[node];
        }        

    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        for(int i = 1; i<n; i++){
            int u = parent[i];
            int v = i;

            adj[u].push_back(v);
        }

        resSize.assign(n, 1);
        lastAnces.assign(26, -1);

        dfs(0, s, parent);

        return resSize;

        
    }
};