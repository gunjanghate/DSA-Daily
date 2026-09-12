class Solution {
public:

    int solve(
        int node,
        int parent,
        int d,
        vector<vector<int>>& adj,
        vector<int>& coins,
        int k,
        vector<vector<int>>& dp
    ) {

        if(d >= 15) d = 14;

        if(dp[node][d]!=-1) return dp[node][d];

        int curr = coins[node] >> d;

        int nothalves = curr - k;
        for(auto a : adj[node]){
            if(a==parent) continue;

            nothalves += solve(
                a, node, d, adj, coins, k, dp
            );
        }
        int halves = floor(curr / 2);
        for(auto a : adj[node]){
            if(a==parent) continue;

            halves += solve(
                a, node, d+1, adj, coins, k, dp
            );
        }


        return dp[node][d] = max(nothalves, halves);

    }


    int maximumPoints(
        vector<vector<int>>& edges,
        vector<int>& coins,
        int k
    ) {

        int n = coins.size();

        vector<vector<int>> adj(n);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> dp(n, vector<int>(15, -1));

        return solve(0, -1, 0, adj, coins, k, dp);
    }
};