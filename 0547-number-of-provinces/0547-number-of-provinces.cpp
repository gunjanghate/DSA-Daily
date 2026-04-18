class Solution {
private:
    void dfs(int i, vector<vector<int>> &adjList, vector<int> &vis){
        vis[i] = 1;
        for(auto it : adjList[i]){
            if(!vis[it]) dfs(it, adjList, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<vector<int>> adjList(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjList, vis);
            }
        }

        return cnt;
    }
};