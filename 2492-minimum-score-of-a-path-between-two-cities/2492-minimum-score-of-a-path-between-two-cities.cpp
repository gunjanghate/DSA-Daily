class Solution {
public:

    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, int &ans){
        vis[node] = 1;

        for(auto [next, wt] : adj[node]){
            ans = min(ans, wt);
            if(!vis[next]){
                dfs(next, adj, vis, ans);
            }
        }

    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        vector<int> vis(n+1, 0);
        int ans = INT_MAX;
        dfs(1, adj, vis, ans);

        return ans;
    }
};